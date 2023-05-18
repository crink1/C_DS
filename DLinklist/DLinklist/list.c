#include"list.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

ListNode* LTInit()
{
	ListNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;
}

bool IsEmpty(ListNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

void LTPushBank(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead, x);
	/*ListNode* newnode = BuyListNode(x);
	ListNode* prev = phead->prev;
	newnode->prev = prev;
	newnode->next = phead;
	prev->next = newnode;
	phead->prev = newnode;*/
}

void LTPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead->next, x);
	/*ListNode* newnode = BuyListNode(x);
	ListNode* next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = next;
	next->prev = newnode;*/
}

void LTPopBank(ListNode* phead)
{
	assert(phead);
	assert(!IsEmpty(phead));
	ListErase(phead->prev);
	/*ListNode* prev = phead->prev->prev;
	ListNode* cur = phead->prev;
	prev->next = phead;
	phead->prev = prev;
	free(cur);*/
}

void LTPopFront(ListNode* phead)
{
	assert(phead);
	assert(!IsEmpty(phead));
	ListErase(phead->next);
	/*ListNode* next = phead->next->next;
	ListNode* cur = phead->next;
	phead->next = next;
	next->prev = phead;
	free(cur);*/
}

ListNode* LTFind(ListNode* phead,LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}

void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void LTPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<==>", cur->data);
		cur = cur->next;
	}
}

void LTDestroy(ListNode* phead)
{
	ListNode* cur = phead->next;
	ListNode* next = cur->next;
	while (cur != phead)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}