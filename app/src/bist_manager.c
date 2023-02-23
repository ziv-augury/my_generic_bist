
#include <zephyr/sys/printk.h>

#include <zephyr/devicetree.h>

#include "bist_manager.h"
#include "my_device.h"


#define DEVICE_PTR_IF_NODE_HAS_PROP_BIST_ELSE_NONE(node_id) \
    COND_CODE_1(DT_NODE_HAS_PROP(node_id, bist), \
            (DEVICE_DT_GET(node_id),), ())

const struct device *devs_with_bist_prop[] = {
    DT_FOREACH_NODE(DEVICE_PTR_IF_NODE_HAS_PROP_BIST_ELSE_NONE)
};




void run_all_bists(void)
{
    printk("Enter the Bist!\n");

    for (size_t i = 0; i < ARRAY_SIZE(devs_with_bist_prop); i++) 
    {
        my_bist_run(devs_with_bist_prop[i], NULL);
    }

    printk("done the Bist!\n");

}