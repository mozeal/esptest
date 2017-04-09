#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"

void pingTask(void *pvParameters)
{
    while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        printf("ping\n");
    }
}

void app_main()
{
    // xTaskCreatePinnedToCore( pvTaskCode, pcName, usStackDepth, pvParameters, 
    //     uxPriority, pxCreatedTask, xCoreID )
    xTaskCreatePinnedToCore(&pingTask, "pingTask", 2048, NULL, 5, NULL, 0);
}


