/*
    recordar usar un transistor para llevar a niveles de 5v
*/

#include "driver/gpio.h"


//1 salida es 0 de entrada

typedef struct colores {
    char red;
    char green;
    char blue;
    gpio_num_t data_pin;
    gpio_num_t clock_pin;
}color;


void set_color(color *led ,char red,char green,char blue);
void print_color(color *led);
void leds_init(color*led,gpio_num_t data_pin,gpio_num_t clock_pin);//inicia los pines con valor = 0
