#include "leds.h"
#include "stdint.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
void set_color(color *led ,char red,char green,char blue){
    (*led).red=red;
    (*led).green=green;
    (*led).blue=blue;

}

void leds_init(color*led,gpio_num_t data_pin,gpio_num_t clock_pin){
    (*led).data_pin=data_pin;
    (*led).clock_pin=clock_pin;
    gpio_set_direction(data_pin,GPIO_MODE_OUTPUT);
    gpio_set_direction(clock_pin,GPIO_MODE_OUTPUT);
    gpio_set_level(data_pin,1);
    gpio_set_level(clock_pin,1);
}


void print_color(color *led){
    uint32_t datos;

    datos= ((*led).red) | ((*led).green<<8) | ((*led).blue<<16); //agregar los colores
    datos =datos| (0b11<<30) | (0b11 & (((*led).blue>>6)<<28)) | (0b11 & (((*led).green>>6)<<26)) | (0b11 & (((*led).red>>6)<<24)); //primer byte con formato "1 1 /B7 /B6 /G7 /G6 /R7 /R6"

    datos =~datos;

    for(int i=31;i>=0;i--){
        gpio_set_level((*led).clock_pin,1);
        //              inicio logica

        gpio_set_level((*led).data_pin, (0x1&  (datos>>i)  ) );

        //              fin logica
        vTaskDelay(1);
        gpio_set_level((*led).clock_pin,0);
        vTaskDelay(1);
    }

}
