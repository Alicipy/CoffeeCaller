# SPDX-FileCopyrightText: 2025 Alicipy <dev@stefankraus.org>
#
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources_ifdef(CONFIG_FAKE_LED_STRIP fake_led_strip.c)
