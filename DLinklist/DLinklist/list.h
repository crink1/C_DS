#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* prev;
	LTDataType data;
	struct ListNode* next;
}ListNode;


ListNode* BuyListNode(LTDataType x);

ListNode* LTInit();

void LTPrint(ListNode* phead);

void LTPushBank(ListNode* phead,LTDataType x);

void LTPushFront(ListNode* phead, LTDataType x);

void LTPopBank(ListNode* phead);

void LTPopFront(ListNode* phead);

ListNode* LTFind(ListNode* phead,LTDataType x);

void ListErase(ListNode* pos);

void ListInsert(ListNode* pos, LTDataType x);

void LTDestroy(ListNode* phead);