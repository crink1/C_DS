#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QDataType;

typedef struct QNode
{
	struct QNode* next;
	QDataType data;

}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

void QueueInit(Queue* pq);

void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq,QDataType x);

void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);

QDataType QueueBack(Queue* pq);

int QueueSize(Queue* pq);

bool QueueEmpty(Queue* pq);
