#include"list.h"

void test1()
{
	ListNode* plist = LTInit();
	LTPushBank(plist, 1);
	LTPushBank(plist, 2);
	LTPushBank(plist, 3);
	LTPushBank(plist, 4);
	LTPushBank(plist, 5);
	LTPushFront(plist, 0);
	LTPushFront(plist, 9);
	LTPopBank(plist);
	LTPopFront(plist);
	ListNode* tmp=LTFind(plist,3);
	ListInsert(tmp, 6);
	ListErase(LTFind(plist,2));
	LTPrint(plist);
	LTDestroy(plist);
	plist = NULL;
	
}

int main()
{
	
	test1();
	return 0;
}