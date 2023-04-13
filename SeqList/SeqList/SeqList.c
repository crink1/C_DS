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
	SLCheckCapacity(psl);
	psl->a[psl->size] = x;
	psl->size++;
}

void SLPushFront(SL* psl, DateType x);

void SLPopBack(SL* psl);

void SLPopFront(SL* psl);

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