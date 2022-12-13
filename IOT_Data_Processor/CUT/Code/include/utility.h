#pragma once
#ifndef __UTILITY_H__
#define __UTILITY_H__


extern void freeLinkedList(iotdata** headPointer);
extern void appendLinkedList(iotdata **headPointer, iotdata* data);
extern void display_iotdata(iotdata* ct);
extern void printLinkedList(iotdata *ct);
extern int loadFromFile(const char *fileName, iotdata **headPointer);


#endif
