
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

void vSenderTask(void *pvParameters)
{
	long lValueToSend;
	portBASE_TYPE xStatus;

	lValueToSend = (long)pvParameters;

	while (1)
	{
		xStatus = xQueueSendToBack(xQueue, &lValueToSend, 0);

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
	long lReceivedValue;
	portBASE_TYPE xStatus;
	const portTickType xTicksToWait = 100 / portTICK_RATE_MS;

	while (1)
	{
		if (uxQueueMessagesWaiting(xQueue) != 0)
		{
			printf("Queue should have been empty!\r\n");
		}

		xStatus = xQueueReceive(xQueue, &lReceivedValue, xTicksToWait);
		if (xStatus == pdPASS)
		{
			printf("Received= %d\r\n", lReceivedValue);
		}
		else
		{
			printf(" Could not receive from the queue.\r\n");
		}
	}

}