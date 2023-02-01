
#include <sys/printk.h>

#include "bist_manager.h"
#include "my_device.h"
// #include "drivers_list.h"

void run_all_bists(void)
{
    printk("Enter the Bist!\n");
    // // LOG_INF("\n===========================================\n BIST START \n ================================");
    // const struct device* my_bist_drvs = device_get_binding("MY_BIST_DRVS");
    // int num_of_devs = my_drv_list_len(my_bist_drvs);
    // while( num_of_devs )
    // {
    //     const struct device* dev = my_drv_list_get_next_dev(my_bist_drvs);
    //     if( dev )
    //     {
    //         my_bist_run(dev, NULL);
    //     }
    //     num_of_devs--;
    // }
    // LOG_INF("\n===========================================\n BIST END \n ================================");

    printk("done the Bist!\n");

}