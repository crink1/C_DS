#include"heap.h"

void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

void HPDstroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

void Swap(HPDataType *a, HPDataType *b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}


void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;

		}
		else
		{
			break;
		}

	}
}

void HPPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (NULL == tmp)
		{
			perror("relloc fail");
			return;
		}
		php->capacity = newcapacity;
		php->a = tmp;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size - 1);

}


void AdjustDwon(HPDataType* a, int sz, int parent)
{
	int child = parent * 2 + 1;
	while (child < sz)
	{
		if (child+1 < sz && a[child + 1] < a[child])
		{
			child++;

		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child= parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HPPop(HP* php)
{
	assert(php);
	assert(!HPEmpty(php));
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDwon(php->a, php->size, 0);

}


bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

HPDataType HPTop(HP* php)
{
	assert(php);
	return php->a[0];
}

int HPSize(HP* php)
{
	assert(php);
	return php->size;
}