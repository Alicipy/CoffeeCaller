/*
 * SPDX-FileCopyrightText: 2025 Alicipy <dev@stefankraus.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

/**
 * @brief Initialize watchdog from the device tree
 *
 */
void watchdog_init(void);

/**
 * @brief Feed the dog to keep it happy
 *
 */
void watchdog_feed(void);
