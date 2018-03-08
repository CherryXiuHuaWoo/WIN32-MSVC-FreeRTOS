
/* Standard includes. */
#include "UserTask.h"

#include <stdio.h>
#include <stdlib.h>

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
	volatile unsigned long u1;

	pcTaskName = (char *)pvParameters;

	while (1)
	{
		printf("%s", pcTaskName);

		for (u1 = 0; u1 < mainDelayTime; u1++)
		{
		}
	}
}