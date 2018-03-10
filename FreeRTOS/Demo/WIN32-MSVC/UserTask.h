#pragma once

typedef struct
{
	unsigned char ucValue;
	unsigned char ucSource;
}xData;

void vSenderTask(void *pvParameters);
void vReciverTask(void *pvParameters);
