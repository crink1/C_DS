#include"queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	while (pq->phead)
	{
		QNode* cur = pq->phead;
		pq->phead = pq->phead->next;
		free(cur);
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->next = NULL;
	newnode->data = x;
	if (pq->phead == 0)
	{
		assert(pq->ptail == NULL);
		pq->phead = pq->ptail = newnode;

	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = pq->ptail->next;
	}
	
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QNode* cur = pq->phead;
	if (pq->phead->next == NULL)
	{
		free(cur);
		pq->phead = pq->ptail = NULL;
		
	}
	else
	{
		pq->phead = pq->phead->next;
		free(cur);
	}
	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->phead->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->ptail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL && pq->ptail == NULL;
}