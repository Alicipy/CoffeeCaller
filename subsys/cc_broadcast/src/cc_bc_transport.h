/*
 * SPDX-FileCopyrightText: 2025 Alicipy <dev@stefankraus.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

void transport_send_raw(const char *payload);

#ifdef CONFIG_ZTEST
void cc_bc_transport_reset(void);
#endif /* CONFIG_ZTEST */