
#pragma once


#include <zephyr/types.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/flash.h>

#include <errno.h>


typedef int (*my_bist_run_t)(const struct device *dev, void* context); 


__subsystem struct my_device_api {    // this type will be passed to the DT init
    union all_apis {
        struct sensor_driver_api sensor_api;
        struct flash_driver_api flash_api;
    } all_apis;

    my_bist_run_t bist_run;
};


static inline int my_bist_run(const struct device *dev, void* context)
{
    const struct my_device_api *api =(const struct my_device_api *)dev->api;
    if (api->bist_run == NULL) {
        return -ENOSYS;
    }
    return api->bist_run(dev, context);
}
