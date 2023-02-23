
#ifdef CONFIG_SEN3

#include <zephyr/init.h>
#include "my_device.h"

#include "sen3.h"
#include <sen3_defs.h>


#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(SEN3, CONFIG_SENSOR_LOG_LEVEL);


static int sen3_attr_set(const struct device *dev, enum sensor_channel chan, 
                         enum sensor_attribute attr,
                         const struct sensor_value *val)
{
    LOG_INF("from all your attribute you chose this one ?? \n");
    return 0;
}

int sen3_sample_fetch(const struct device *dev, enum sensor_channel chan)
{
    LOG_INF("you can fetch it yourself\n");
    return 0;
}

int sen3_bist(const struct device *dev, void* context)
{
    LOG_INF("sen3 bist result - i m your dady :) \n");
    return 0;
}

static const struct my_device_api sen3_driver_api = {
	.all_apis.sensor_api = {
		.attr_set = sen3_attr_set,
		.trigger_set = NULL,
		.sample_fetch = sen3_sample_fetch,
		.channel_get = NULL,
	},

	.bist_run = sen3_bist,
};

/////////////////////////////////////////////////////////////////////
//////////  INIT RELATED FUNCTIONS:

static int sen3_init(const struct device *dev)
{
    LOG_INF("sen3_init done\n");
    return 0;
}

#define DT_DRV_COMPAT my_sen3

struct sen3_data {
    int test;
} my_sen3_data;

struct sen3_config {
    int test;
} my_sen3_config;


DEVICE_DT_INST_DEFINE(
    0,
    sen3_init, 
    NULL,
    &my_sen3_data, //&sen3_data_0, 
    &my_sen3_config, //&sen3_config_0, 
    APPLICATION,
    CONFIG_SENSOR_INIT_PRIORITY, 
    &sen3_driver_api
);

// DT_INST_FOREACH_STATUS_OKAY(SEN3_INIT)

#endif // CONFIG_SEN3