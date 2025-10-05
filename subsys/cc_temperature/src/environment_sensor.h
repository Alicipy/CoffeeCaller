/*
 * SPDX-FileCopyrightText: 2025 Alicipy <dev@stefankraus.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <zephyr/device.h>

typedef struct
{
    double temperature;
    double humidity;
} climate_data_t;

int initialize_sht_sensor(const struct device** sht_dev);
int read_climate_data(const struct device* sht_dev, climate_data_t* climate_data);