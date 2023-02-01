/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <my_device.h>
#include <sys/printk.h>

#include "bist_manager.h"


void main(void)
{
	printk("Hello World! %s\n", CONFIG_BOARD);
	const struct device* dev = device_get_binding("SENSOR1");
	
	if( ! dev)
	{
		printk("dev not init well");
		return;
	}
	sensor_attr_set(dev, 0, 0, NULL);
	run_all_bists();
	k_sleep(K_MSEC(5000));
	printk("done by by");
}
