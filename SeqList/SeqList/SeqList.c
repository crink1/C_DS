#include"SeqList.h"

void SLInit(SL* psl)
{
	psl->a = (DateType*)malloc(sizeof(DateType) * 4);
	if (NULL == psl->a)
	{
		perror("malloc fail");
	}
	psl->capacity = 4;
	psl->size = 0;
}

void SLCheckCapacity(SL* psl)
{
	if (psl->size == psl->capacity)
	{
		DateType* tmp = (DateType*)realloc(psl->a, sizeof(DateType) * psl->capacity * 2);
		if (NULL == tmp)
		{
			perror("realloc fail");
			return;
		}
		psl->a = tmp;
		psl->capacity *= 2;
	}
}

void SLPushBack(SL* psl, DateType x)
{
	assert(psl != NULL);
	/*SLCheckCapacity(psl);
	psl->a[psl->size] = x;
	psl->size++;*/
	SLInsert(psl, psl->size, x);
}

void SLPushFront(SL* psl, DateType x)
{
	assert(psl != NULL);
	/*SLCheckCapacity(psl);
	int end = psl->size - 1;
	while (end >= 0)
	{
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->a[0] = x;
	psl->size++;*/
	SLInsert(psl, 0, x);
	
}

void SLPopBack(SL* psl)
{
	assert(psl != NULL);
	assert(psl->size > 0);
	psl->size--;
}

void SLPopFront(SL* psl)
{
	assert(psl != NULL);
	assert(psl->size > 0);
	int start = 0;
	while (start < psl->size - 1)
	{
		psl->a[start] = psl->a[start + 1];
		start++;

	}
	psl->size--;
}

void SLInsert(SL* psl, int pos, DateType x)
{
	assert(psl != NULL);
	assert(pos >= 0 && pos <= (psl->size));
	SLCheckCapacity(psl);
	int end = psl->size-1;
	for (end = psl->size - 1; end >= pos; end--)
	{
		psl->a[end + 1] = psl->a[end];
	}
	psl->a[pos] = x;
	psl->size++;
}

void SLModify(SL* psl, int pos, DateType x)
{
	assert(psl != NULL);
	assert(pos >= 0 && pos < (psl->size));
	psl->a[pos] = x;
}

int SLFind(SL* psl, DateType x)
{
	assert(psl != NULL);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}
	return -1;

}

void SLEares(SL* psl, int pos)
{
	assert(psl != NULL);
	assert(pos >= 0 && pos < (psl->size));
	for (int start = pos; start < psl->size-1; start++)
	{
		psl->a[start] = psl->a[start + 1];
	}
	psl->size--;
}

void SLPrint(SL* psl)
{
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d\n", psl->a[i]);
	}
}

void SLDestroy(SL* psl)
{
	free(psl->a);
	psl->a = NULL;
	psl->capacity = 0;
	psl->size = 0;
}