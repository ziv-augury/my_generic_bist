

#include <init.h>
#include "my_device.h"
#include "drivers_list.h"

#include <logging/log.h>
LOG_MODULE_REGISTER(AUGU_DRIVERS, 3);


#define AUGU_DRIVERS_NAME_BY_IDX(node_id, i)                                \
    {                                                                       \
        .name = DT_PROP(DT_PHANDLE_BY_IDX(node_id, bist_drvs, i), label) \
    },
#define AUGU_DRIVERS_ITEMS_FUNC(child, node_id) AUGU_DRIVERS_NAME_BY_IDX(node_id, child)
#define AUGU_DRIVERS_LIST_LEN(node_id) DT_PROP_LEN(node_id, bist_drvs)
#define AUGU_DRIVERS_NAMES(node_id) {               \
    UTIL_LISTIFY(AUGU_DRIVERS_LIST_LEN(node_id),    \
                 AUGU_DRIVERS_ITEMS_FUNC,           \
                 node_id)                           \
    }


struct my_driver_name {
    const char* name;
};

struct my_drivers_config {
    const struct my_driver_name *my_drv_names;
    int                          num_of_drvs;
};

static const struct my_driver_name my_drv_names[] = AUGU_DRIVERS_NAMES(DT_CHOSEN(augury_bist_drvs)); \
static const struct my_drivers_config my_drivers_config = { \
    .my_drv_names = my_drv_names,                                   \
    .num_of_drvs = AUGU_DRIVERS_LIST_LEN(DT_CHOSEN(augury_bist_drvs)),           \
};                                                                  \



const struct device* my_drv_list_get_next_dev(const struct device *dev)
{
    const struct my_drivers_config *config = dev->config;
    static idx = 0;
    if( config->num_of_drvs > idx)
    {
        const struct device *temp_dev = device_get_binding(config->my_drv_names[idx].name);
        idx++;
        if( temp_dev )
        {
            return temp_dev;
        }
        else
        {
            LOG_INF("dev binding fail");
            return NULL;
        }
    }
    else
    {
        idx = 0;
        LOG_INF("no more devs");
        return NULL;
    }
}


int my_drv_list_len(const struct device *dev)
{
    const struct my_drivers_config *config = dev->config;
    return config->num_of_drvs;
}


// static int augu_drivers_init(const struct device *dev)
// {
//     LOG_INF("augu drivers init: %s", dev->name);
//     return 0;
// }
// #define DT_DRV_COMPAT augury_driver
// #define AUGU_DRIVERS_INIT(n)    \
//     static const struct augu_driver_name augu_drv_names_##n[] = AUGU_DRIVERS_NAMES(DT_DRV_INST(n)); \
//     static const struct augu_drivers_config augu_drivers_config_##n = { \
//         .augu_drv_names = augu_drv_names_##n,                                   \
//         .num_of_drvs = AUGU_DRIVERS_LIST_LEN(DT_DRV_INST(n)),           \
    // };                                                                  \
                                                                        \
    // DEVICE_DT_INST_DEFINE(n, augu_drivers_init, NULL,                   \
    //     NULL, &augu_drivers_config_##n, APPLICATION,                    \
    //     CONFIG_SENSOR_INIT_PRIORITY, NULL);
// DT_INST_FOREACH_STATUS_OKAY(AUGU_DRIVERS_INIT)
// #endif /*  CONFIG_AUGU_DRIVERS  */