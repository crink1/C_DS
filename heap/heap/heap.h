#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;

typedef struct HeapNode
{
	HPDataType* a;
	int size;
	int capacity;

}HP;


void Swap(HPDataType* a, HPDataType* b);

void AdjustUp(HPDataType* a, int child);

void AdjustDwon(HPDataType* a, int sz,int parent);

void HPInit(HP* php);

void HPDstroy(HP* php);

void HPPush(HP* php,HPDataType x);

void HPPop(HP* php);

bool HPEmpty(HP* php);

HPDataType HPTop(HP* php);

int HPSize(HP* php);

