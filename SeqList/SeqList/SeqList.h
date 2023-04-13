#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int DateType;

typedef struct SeqList
{
	DateType* a;
	int size;
	int capacity;
}SL;


void SLInit(SL* psl);

void SLPushBack(SL* psl,DateType x);

void SLPushFront(SL* psl, DateType x);

void SLPopBack(SL* psl);

void SLPopFront(SL* psl);

void SLPrint(SL* psl);

void SLDestroy(SL* psl);
