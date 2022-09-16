#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"

int main(void)
{
    cy_rslt_t result;

    /* Initialize the device and board peripherals */
    result = cybsp_init() ;
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    __enable_irq();

    cyhal_gpio_init(CYBSP_USER_LED , CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG , 1);
    cyhal_gpio_init(CYBSP_USER_BTN, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_PULLUP, 1);

    for (;;)
    {
    	if(cyhal_gpio_read(CYBSP_USER_BTN)==1){
    		cyhal_gpio_write(CYBSP_USER_LED, 1);
    	}else{
    		cyhal_gpio_write(CYBSP_USER_LED, 0);
    	}
    }
}

