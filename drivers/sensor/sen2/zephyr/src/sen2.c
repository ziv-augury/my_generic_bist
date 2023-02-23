
#ifdef CONFIG_SEN2

#include <zephyr/init.h>
#include "my_device.h"

#include "sen2.h"
#include <sen2_defs.h>


#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(SEN2, CONFIG_SENSOR_LOG_LEVEL);


static int sen2_attr_set(const struct device *dev, enum sensor_channel chan, 
                         enum sensor_attribute attr,
                         const struct sensor_value *val)
{
    LOG_INF("from all your attribute you chose this one ?? \n");
    return 0;
}

int sen2_sample_fetch(const struct device *dev, enum sensor_channel chan)
{
    LOG_INF("you can fetch it yourself\n");
    return 0;
}

int sen2_bist(const struct device *dev, void* context)
{
    LOG_INF("sen2 bist result - whos your dady??\n");
    return 0;
}

static const struct my_device_api sen2_driver_api = {
	.all_apis.sensor_api = {
		.attr_set = sen2_attr_set,
		.trigger_set = NULL,
		.sample_fetch = sen2_sample_fetch,
		.channel_get = NULL,
	},

	.bist_run = sen2_bist,
};

/////////////////////////////////////////////////////////////////////
//////////  INIT RELATED FUNCTIONS:

static int sen2_init(const struct device *dev)
{
    LOG_INF("sen2_init done\n");
    return 0;
}

#define DT_DRV_COMPAT my_sen2

struct sen2_data {
    int test;
} my_sen2_data;

struct sen2_config {
    int test;
} my_sen2_config;


DEVICE_DT_INST_DEFINE(
    0,
    sen2_init, 
    NULL,
    &my_sen2_data, //&sen1_data_0, 
    &my_sen2_config, //&sen1_config_0, 
    APPLICATION,
    CONFIG_SENSOR_INIT_PRIORITY, 
    &sen2_driver_api
);

// DT_INST_FOREACH_STATUS_OKAY(SEN1_INIT)

#endif // CONFIG_SEN2