
/* Standard includes. */
#include "UserTask.h"

#include <stdio.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"

#define	mainDelayTime	1000000

/*
 * Function Name: vTaskFunction
 * Description: vTaskFunction
 * Input: 
 *			pvParameters --- Parameters Pointer
 * Output:
 * Return: None
 */
void vTaskFunction(void *pvParameters)
{

	char *pcTaskName;
	portTickType xLastWakeTime;
	volatile unsigned long u1;

	pcTaskName = (char *)pvParameters;

	/*Save the current TickTime Value.
	 *Here is the only time for xLastWakeTime to assign.
	 *xLaskWakeTime will be updated in vTaskDelayUntil.
	 */
	xLastWakeTime = xTaskGetTickCount;

	while (1)
	{
		printf("Time0=%d,%s", (int)xLastWakeTime, pcTaskName);
		
		//while (1) {};
		//vTaskDelay(250 / portTICK_RATE_MS);
		vTaskDelayUntil(&xLastWakeTime, (250 / portTICK_RATE_MS));
		printf("Time1=%d\r\n", (int)xLastWakeTime);
	}

	while (1)
	{
	}
}