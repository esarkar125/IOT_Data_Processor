#pragma once
#ifndef _STRUCT_H_
#define _STRUCT_H_


#define CITY_LEN 100
#define DATE_LEN 20
#define DATA_LINE_BUFFER 200

typedef struct _iotdata
{
	char city[CITY_LEN];
	int code;
	char date[DATE_LEN];
	int temperature;
	int humidity;
	float pm25;
	float pm10;
	float no2;
	struct _iotdata *next;
} iotdata;


#endif
