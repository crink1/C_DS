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


//创建新节点
ListNode* BuyListNode(LTDataType x);
//初始化链表
ListNode* LTInit();
//打印链表
void LTPrint(ListNode* phead);
//尾部插入
void LTPushBank(ListNode* phead,LTDataType x);
//头部插入
void LTPushFront(ListNode* phead, LTDataType x);
//尾部删除
void LTPopBank(ListNode* phead);
//头部删除
void LTPopFront(ListNode* phead);
//查找节点
ListNode* LTFind(ListNode* phead,LTDataType x);
//删除节点
void ListErase(ListNode* pos);
//插入数据
void ListInsert(ListNode* pos, LTDataType x);
//删除链表
void LTDestroy(ListNode* phead);