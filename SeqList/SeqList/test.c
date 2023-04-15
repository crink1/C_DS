#include"SeqList.h"
int main()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPushFront(&sl, -1);
	SLPushFront(&sl, -4);
	SLPushFront(&sl, -2);
	
	int i = SLFind(&sl, 4);
	if (i != -1)
	{
		SLEares(&sl, i);
	}
	SLInsert(&sl, 6, 6);
	SLPopBack(&sl);
	SLPopFront(&sl);
	SLModify(&sl, 0, 9);
	SLPrint(&sl);
	SLDestroy(&sl);
	return 0;
}