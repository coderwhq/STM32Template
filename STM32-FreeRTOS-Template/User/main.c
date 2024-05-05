#include "stm32f10x.h" // Device header

/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "task.h"

/* Functions definitions */
void Peripherals_Init(void);

/* Task functions definitions */
void AppTaskCreate(void *parameter);

/* Task functions handle definitions */
TaskHandle_t appTaskCreateHandle = NULL;

int main(void)
{
    BaseType_t xReturn = pdPASS;
    Peripherals_Init();

    xReturn = xTaskCreate(AppTaskCreate, "AppTaskCreate", 128, NULL, 1, &appTaskCreateHandle);

    if (xReturn == pdPASS)
    {
        vTaskStartScheduler();
    }

    while (1)
    {
    }
}


void Peripherals_Init(void)
{
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

}

void AppTaskCreate(void *parameter)
{
    BaseType_t xReturn = pdPASS;
    taskENTER_CRITICAL();

    vTaskDelete(appTaskCreateHandle);
    taskEXIT_CRITICAL();
}
