/*
 * SPDX-FileCopyrightText: 2025 Alicipy <dev@stefankraus.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

void dispatch_cc_bc_message_handler(char* json_message);

#ifdef CONFIG_ZTEST
void cc_bc_client_reset(void);
#endif /* CONFIG_ZTEST */