#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "lib/button.h"
#include "lib/led.h"

#define LED_R 13
#define LED_G 11
#define LED_B 12

#define BTN_PIN 5

#define intervalo 3000

bool led_stat_r = false;
bool led_stat_g = false;
bool led_stat_b = false;

int64_t turn_off_callback(alarm_id_t, void *user_data);

int main()
{
    stdio_init_all();
    led_init(LED_R);
    led_init(LED_G);
    led_init(LED_B);
    button_init(BTN_PIN);

    while (true) {
        if(!gpio_get(BTN_PIN) && !led_stat_r && !led_stat_g && !led_stat_b) {
            sleep_ms(50);
            if(!gpio_get(BTN_PIN)){
                gpio_put(LED_R, true);
                gpio_put(LED_G, true);
                gpio_put(LED_B, true);

                led_stat_r = true;
                led_stat_g = true;
                led_stat_b = true;

                add_alarm_in_ms(intervalo, turn_off_callback, NULL, false);
            }
        }
        sleep_ms(20);
    }
}

int64_t turn_off_callback(alarm_id_t, void *user_data){
    
}