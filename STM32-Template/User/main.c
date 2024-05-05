#include "stm32f10x.h" // Device header

/* Functions definitions */
void Peripherals_Init(void);

int main(void)
{

    while (1)
    {
    }
}


void Peripherals_Init(void)
{
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

}

