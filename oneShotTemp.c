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

typedef enum {turn_off_green, turn_off_blue, turn_off_red} Led_State;

static Led_State led_state = turn_off_green;

int64_t turn_off_callback(alarm_id_t, void *user_data);

int main()
{
    stdio_init_all();
    led_init(LED_R);
    led_init(LED_G);
    led_init(LED_B);
    button_init(BTN_PIN);

    while (true) {
        if(!gpio_get(BTN_PIN) && !gpio_get(LED_R) && !gpio_get(LED_G) && !gpio_get(LED_B)) {
            sleep_ms(50);
            if(!gpio_get(BTN_PIN)){
                printf("Botao pressionado\n");
                gpio_put(LED_R, true);
                gpio_put(LED_G, true);
                gpio_put(LED_B, true);

                // Programa um alarme para daqui a 3 segundos para desativar o led verde
                add_alarm_in_ms(intervalo, turn_off_callback, NULL, false);
            }
        }
        sleep_ms(20);
    }
}

int64_t turn_off_callback(alarm_id_t, void *user_data)  {
    switch(led_state) {
        case turn_off_green:
            printf("Desligando led verde\n");
            gpio_put(LED_G, false);
            led_state = turn_off_blue;
            // Alarme para desativar o botão azul
            add_alarm_in_ms(intervalo, turn_off_callback, NULL, false);
            break;
        case turn_off_blue:
            printf("Desligando led azul\n");
            gpio_put(LED_B, false);
            led_state = turn_off_red;
            // Alarme para desativar o botão azul
            add_alarm_in_ms(intervalo, turn_off_callback, NULL, false);
            break;
        case turn_off_red:
            printf("Desligando led vermelho\n");
            gpio_put(LED_R, false);
            led_state = turn_off_green;
            break;
        default:
            printf("Estado incerto\n");
            break;
    }
    return 0;
}