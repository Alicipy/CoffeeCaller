# SPDX-FileCopyrightText: 2025 Alicipy <dev@stefankraus.org>
#
# SPDX-License-Identifier: Apache-2.0

add_subdirectory_ifdef(CONFIG_LED_STRIP led_strip)
add_subdirectory_ifdef(CONFIG_PWM pwm)
