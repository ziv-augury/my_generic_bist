
#pragma once


#include <zephyr/types.h>
#include <device.h>
#include <drivers/sensor.h>
#include <drivers/flash.h>
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


// const struct device* my_get_dev(const struct device *dev);
// int my_get_num_of_devs(const struct device *dev);
