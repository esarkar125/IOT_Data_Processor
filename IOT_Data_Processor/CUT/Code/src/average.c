/********************************************************
* Filename: average.c
* Author: group8
*********************************************************/


//headers

#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#include <unistd.h>
#include <string.h>


//avgTemperature

void avgTemperature(iotdata *head)
{
    for(int i=1;i<13;i++)
    {
        int count = 0;
        float temp = 0.0;
        float avgTemperature;
        char mon[3];
	mon[2] = '\0';
    	iotdata *iter = head;

        while(iter!= NULL)
        {
        	mon[0] = iter->date[3];
	    	mon[1] = iter->date[4];
                if(atoi(mon) == i)
                {
                	temp += iter->temperature;
                	count++;
            	}
            	iter = iter->next;
        }
        
        if(count!=0)
        {	
        	avgTemperature = temp/count;
        }
        
        printf("Month %2d -> %.2f\t", i, avgTemperature);
        for(int i=0; i<avgTemperature/2; i++)
        {
        	printf("■");
        }
        printf("\n");
    }
}


//avgHumidity

void avgHumidity(iotdata *head)
{
    for(int i=1;i<13;i++)
    {
        int count = 0;
        float temp = 0.0;
        float avgHumidity;
        char mon[3];
	mon[2] = '\0';
    	iotdata *iter = head;
        while(iter!= NULL)
        {
	    	mon[0] = iter->date[3];
	    	mon[1] = iter->date[4];
                if(atoi(mon) == i)
            	{
                	temp += iter->humidity;
                	count++;
            	}
            	iter = iter->next;
        }
        
        if(count!=0)
        {
        	avgHumidity = temp/count;
        }
        printf("Month %2d -> %.2f\t", i, avgHumidity);
        for(int i=0; i<avgHumidity/2; i++)
        {
        	printf("■");
        }
        printf("\n");
    }
}


//avgPM25

void avgPM25(iotdata *head)
{   
    for(int i=1;i<13;i++)
    {
    	int count = 0;
        float temp = 0.0;
        float avgPM25;
        char mon[3];
	mon[2] = '\0';
    	iotdata *iter = head;
        while(iter!= NULL)
        {
	    	mon[0] = iter->date[3];
	    	mon[1] = iter->date[4];
            	if(atoi(mon) == i)
            	{
                	temp += iter->pm25;
                	count++;
            	}
            	iter = iter->next;
        }
        
        if(count!=0)
        {
        	avgPM25 = temp/count;
        }
        
        printf("Month %2d -> %.2f\t", i, avgPM25);
        for(int i=0; i<avgPM25/4; i++)
        {
        	printf("■");
        }
        printf("\n");
    }
}


//avgPM10

void avgPM10(iotdata *head)
{   
    for(int i=1;i<13;i++)
    {
        int count = 0;
        float temp = 0;
        float avgPM10;
        char mon[3];
	mon[2] = '\0';
    	iotdata *iter = head;
        while(iter!= NULL)
        {
	    	mon[0] = iter->date[3];
	    	mon[1] = iter->date[4];
            if(atoi(mon) == i)
            {
                temp += iter->pm10;
                count++;
            }
            iter = iter->next;
        }
        
        if(count!=0)
        {
        	avgPM10 = temp/count;
        }
        printf("Month %2d -> %.2f\t", i, avgPM10);
        for(int i=0; i<avgPM10/6; i++)
        {
        	printf("■");
        }
        printf("\n");
    }
}


//avgNO2

void avgNO2(iotdata *head)
{   
    for(int i=1;i<13;i++)
    {
        int count = 0;
        float temp = 0.0;
        float avgNO2;
        char mon[3];
	mon[2] = '\0';
    	iotdata *iter = head;
        while(iter!= NULL)
        {
	    	mon[0] = iter->date[3];
	    	mon[1] = iter->date[4];
            	if(atoi(mon) == i)
            	{
                	temp += iter->no2;
                	count++;
            	}
            	iter = iter->next;
        }
        
        if(count!=0)
        {
        	avgNO2 = temp/count;
        }
        printf("Month %2d -> %.2f\t", i, avgNO2);
        for(int i=0; i<avgNO2/2; i++)
        {
        	printf("■");
        }
        printf("\n");
    }
}
