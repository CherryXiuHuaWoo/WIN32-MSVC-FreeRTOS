
/* Standard includes. */
#include "UserTask.h"

#include <stdio.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"


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
		
		//vTaskDelay(250 / portTICK_RATE_MS);
		vTaskDelayUntil(&xLastWakeTime, (250 / portTICK_RATE_MS));
		printf("Time1=%d\r\n", (int)xLastWakeTime);
	}

	while (1)
	{}
}
extern TaskHandle_t xTask1Handle;
extern TaskHandle_t xTask2Handle;

void vTask1(void *pvParameters)
{
	unsigned portBASE_TYPE uxPriority;

	uxPriority = uxTaskPriorityGet(NULL);

	while (1)
	{
		printf("Task 1 is running\r\n");

		printf("Raise the Task2 priority\r\n");
		vTaskPrioritySet(xTask2Handle, (uxPriority + 1));
	}
}

void vTask2(void *pvParameters)
{
	unsigned portBASE_TYPE uxPriority;

	uxPriority = uxTaskPriorityGet(NULL);

	while (1)
	{
		printf("Task 2 is running\r\n");

		printf("Lower the Task2 priority\r\n");
		vTaskPrioritySet(NULL, (uxPriority - 2));
	}
}