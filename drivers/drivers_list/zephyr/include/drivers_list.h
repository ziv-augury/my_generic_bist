
#pragma once


#include <zephyr/types.h>
#include <device.h>


const struct device* my_drv_list_get_next_dev(const struct device *dev);
int my_drv_list_len(const struct device *dev);