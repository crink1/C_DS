#include"SList.h"
int main()
{
	SListNode *s =NULL;
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPushFront(&s, 6);
	SListPushFront(&s, 8);
	SListInsertAfter(SListFind(s, 4), 9);
	SListPopFront(&s);
	SListPopBack(&s);
	SListPrint(s);

	SListDestroy(&s);

	return 0;
}