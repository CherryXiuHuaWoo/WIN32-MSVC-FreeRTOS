
/* Standard includes. */
#include "UserTask.h"

#include <stdio.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

extern QueueHandle_t xQueue;
extern TaskHandle_t xTask1Handle;
extern TaskHandle_t xTask2Handle;

xData xStructsToSend[2] = 
{
	{ 100, 1},
	{ 200, 2}
};
void vSenderTask(void *pvParameters)
{
	xData *lValueToSend;
	portBASE_TYPE xStatus;

	lValueToSend = (xData *)pvParameters;

	while (1)
	{
		xStatus = xQueueSendToBack(xQueue, lValueToSend, 0);

		if (xStatus != pdPASS)
		{
			printf("Could not send to the queue.\r\n");
		}

		/*Allow other tasks send data.taskYIELD API Fuction: inform Scheduler of joining other task.*/
		taskYIELD();
	}
}

void vReciverTask(void *pvParameters)
{
	xData xReceivedStructure;
	portBASE_TYPE xStatus;
	const portTickType xTicksToWait = 100 / portTICK_RATE_MS;

	while (1)
	{
		if (uxQueueMessagesWaiting(xQueue) != 0)
		{
			printf("Queue should have been empty\r\n");

		}

		xStatus = xQueueReceive(xQueue, &xReceivedStructure, xTicksToWait);
		if (xStatus == pdPASS)
		{
			printf("From Sender %d = %d\r\n", xReceivedStructure.ucSource, xReceivedStructure.ucValue);
		}
		else
		{
			printf(" Could not receive from the queue.\r\n");
		}
	}

}