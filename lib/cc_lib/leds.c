/*
 * SPDX-FileCopyrightText: 2025 Alicipy <dev@stefankraus.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "cc_lib/leds.h"

#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>

LOG_MODULE_REGISTER(cc_leds);

static struct k_sem lock_strip;

#define STRIP_NODE       DT_ALIAS(led_strip)
#define STRIP_NUM_PIXELS DT_PROP(DT_ALIAS(led_strip), chain_length)

leds_color pixels[STRIP_NUM_PIXELS];
static const struct device *const strip = DEVICE_DT_GET(STRIP_NODE);

// Private functions
static void update_strip(void)
{
	int32_t status = led_strip_update_rgb(strip, pixels, STRIP_NUM_PIXELS);
	if (status) {
		LOG_ERR("couldn't update strip: %d", status);
	}
}

// Public functions
void leds_init(void)
{
	if (device_is_ready(strip)) {
		LOG_INF("Found LED strip device %s", strip->name);
	} else {
		LOG_ERR("LED strip device %s is not ready", strip->name);
	}
}

void leds_set_rgb_all(const leds_color *new_color)
{
	if (NULL == new_color) {
		LOG_ERR("New color is null");
		return;
	}

	for (uint8_t i = 0; i < STRIP_NUM_PIXELS; ++i) {
		pixels[i] = *new_color;
	}
  k_sem_give(&lock_strip);
}

void leds_set_rgb_at_pos(const leds_color *new_color, uint8_t pos)
{
	if (NULL == new_color) {
		LOG_ERR("New color is null");
		return;
	}

	if (STRIP_NUM_PIXELS <= pos) {
		LOG_ERR("Position not on LED strip");
		return;
	}

	pixels[pos] = *new_color;
  k_sem_give(&lock_strip);
}

void leds_set_all_off(void)
{
	leds_color all_off = LEDS_RGB(0x0, 0x0, 0x0);
	leds_set_rgb_all(&all_off);
}

uint8_t leds_get_num_of_pixels(void)
{
	return STRIP_NUM_PIXELS;
}

static void led_thread(void *p1, void *p2, void *p3){
  k_sem_init(&lock_strip, 0, 1);
  leds_set_all_off();
  while (1) {
    k_sem_take(&lock_strip, K_FOREVER);
    update_strip();
  }
}

K_THREAD_DEFINE(cc_led_strip, 512, led_thread, NULL, NULL, NULL, 10, 0, 0);
