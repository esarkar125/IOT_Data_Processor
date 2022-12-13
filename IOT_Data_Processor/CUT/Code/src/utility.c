/********************************************************
* Filename: utility.c
* Author: group8
*********************************************************/


//headers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>


//freeLinkedList

void freeLinkedList(iotdata** headPointer)
{
    iotdata* iter = *headPointer;
    // Following code block frees the dynamically memory allocated 
    while ( iter != NULL )
    {
        iotdata* temp = iter ;
        iter = iter -> next ;
        if ( temp != NULL)
		{
			free (temp);
		}
    }
}


//appendLinkedList

void appendLinkedList(iotdata **headPointer, iotdata* data)
{
    iotdata* iter = *headPointer ;

    if ( *headPointer == NULL )
    { 
        *headPointer = data ;
    }
    else
    {
        while ( iter -> next != NULL)
            iter = iter -> next;
        iter -> next = data ;
    }
    data -> next = NULL ;
}


//display_iotdata

void display_iotdata(iotdata* ct)
{
    printf("| %s | %d | %s | %2d | %d | %6.2f | %6.2f | %6.2f |\n",
        ct -> city,
        ct -> code,
        ct -> date,
        ct -> temperature,
        ct -> humidity,
        ct -> pm25,
        ct -> pm10,
        ct -> no2 );
}


//printLinkedList

void printLinkedList(iotdata *ct)
{
    iotdata* iter = ct;
    printf("‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒\n");
    
    while ( iter != NULL )
    {
        display_iotdata(iter);
        iter = iter -> next ;
    }
    
    printf("‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒ ‒\n");
}


//loadFromFile

int loadFromFile(const char *fileName, iotdata **headPointer)
{
	char lineBuffer[DATA_LINE_BUFFER];
	const char* seperator = "," ;
	char* token = NULL ;

	FILE* iotdataFile = fopen (fileName, "r");
	if (iotdataFile == NULL )
    	{
		printf("Issue opening the file %s\n", fileName);
		return EXIT_FAILURE;
	}
	
	fgets ( lineBuffer, DATA_LINE_BUFFER, iotdataFile);
	
	while ( fgets ( lineBuffer, DATA_LINE_BUFFER, iotdataFile) != 0)
	{
		iotdata *iter = (iotdata*)calloc(1, sizeof(struct _iotdata));
		if ( iter == NULL )
		{
			printf("Could not allocate memory !\n");
			break;
		}

		token = strtok (lineBuffer, seperator);
		if ( token != NULL)
		{
			strcpy(iter -> city, token);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> code = atoi(token);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			strcpy(iter -> date, token);
			
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> temperature = atoi(token);
		}


		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> humidity = atoi(token);
		}
		
		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> pm25 = atof(token);
		}
		
		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> pm10 = atof(token);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> no2 = atof(token);
		}
		
		iter -> next = NULL;
		appendLinkedList(headPointer, iter);
	}

	fclose(iotdataFile);
	return EXIT_SUCCESS;
}
