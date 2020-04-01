
#include "sdkconfig.h" // generated by "make menuconfig"

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define SDA_PIN "GPIO_NUM_" STR(CONFIG_ESP_i2c_luz_sda)
#define SCL_PIN "GPIO_NUM_" STR(CONFIG_ESP_i2c_luz_scl)



void i2c_master_init();
void task_max44009_read_ambient_light(void *ignore);