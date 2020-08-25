/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#include <zephyr.h>
#include <stdio.h>
#include <drivers/uart.h>
#include <string.h>

/**@brief Recoverable BSD library error. */
void bsd_recoverable_error_handler(uint32_t err)
{
	printk("bsdlib recoverable error: %u\n", err);
}

void main(void)
{
	at_cmd_write("AT+CGDCONT=2,\"IPV4V6\",\"VZWADMIN\"", NULL, 0, NULL);
	at_cmd_write("AT+CGDCONT=3,\"IPV4V6\",\"VZWINTERNET\"", NULL, 0, NULL);
	at_cmd_write("AT+CGDCONT=4,\"IPV4V6\",\"VZWAPP\"", NULL, 0, NULL);

	printk("The AT host sample started\n");
}
