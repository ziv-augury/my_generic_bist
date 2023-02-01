
#ifdef CONFIG_SEN1

#include <init.h>
#include "my_device.h"

#include "sen1.h"
#include <sen1_defs.h>


#include <logging/log.h>
LOG_MODULE_REGISTER(SEN1, CONFIG_SENSOR_LOG_LEVEL);


static int sen1_attr_set(const struct device *dev, enum sensor_channel chan, 
                         enum sensor_attribute attr,
                         const struct sensor_value *val)
{
    LOG_INF("from all your attribute you chose this one ?? \n");
    return 0;
}

int sen1_sample_fetch(const struct device *dev, enum sensor_channel chan)
{
    LOG_INF("you can fetch it yourself\n");
    return 0;
}

int sen1_bist(const struct device *dev, void* context)
{
    LOG_INF("sen1 bist result - test proves i am a genius\n");
    return 0;
}

static const struct my_device_api sen1_driver_api = {
	.all_apis.sensor_api = {
		.attr_set = sen1_attr_set,
		.trigger_set = NULL,
		.sample_fetch = sen1_sample_fetch,
		.channel_get = NULL,
	},

	.bist_run = sen1_bist,
};

/////////////////////////////////////////////////////////////////////
//////////  INIT RELATED FUNCTIONS:

static int sen1_init(const struct device *dev)
{
    LOG_INF("sen1_init done\n");
    return 0;
}

#define DT_DRV_COMPAT my_sen1

struct sen1_data {
    int test;
} my_data;

struct sen1_config {
    int test;
} my_config;


DEVICE_DT_INST_DEFINE(
    0,
    sen1_init, 
    NULL,
    &my_data, //&sen1_data_0, 
    &my_config, //&sen1_config_0, 
    APPLICATION,
    CONFIG_SENSOR_INIT_PRIORITY, 
    &sen1_driver_api
);

// DT_INST_FOREACH_STATUS_OKAY(SEN1_INIT)

#endif // CONFIG_SEN1