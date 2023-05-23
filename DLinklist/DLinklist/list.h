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


//�����½ڵ�
ListNode* BuyListNode(LTDataType x);
//��ʼ������
ListNode* LTInit();
//��ӡ����
void LTPrint(ListNode* phead);
//β������
void LTPushBank(ListNode* phead,LTDataType x);
//ͷ������
void LTPushFront(ListNode* phead, LTDataType x);
//β��ɾ��
void LTPopBank(ListNode* phead);
//ͷ��ɾ��
void LTPopFront(ListNode* phead);
//���ҽڵ�
ListNode* LTFind(ListNode* phead,LTDataType x);
//ɾ���ڵ�
void ListErase(ListNode* pos);
//��������
void ListInsert(ListNode* pos, LTDataType x);
//ɾ������
void LTDestroy(ListNode* phead);