#include"SList.h"

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == newnode)
	{
		perror("SLT malloc");
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	assert(plist != NULL);
	SListNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	
	SListNode* newnode = BuySListNode(x);
	if (NULL == *pplist)
	{
		
		*pplist = newnode;
	}
	else
	{
		SListNode *tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	if (NULL == (*pplist)->next)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
	

}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* tmp = *pplist;
	*pplist = (*pplist)->next;
	free(tmp);
	tmp = NULL;
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist != NULL);
	SListNode* cur = plist;
	while (cur != NULL)
	{
		if (x == cur->data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode** pos, SLTDateType x)
{
	assert(*pos != NULL);
	SListNode* cur = BuySListNode(x);
	cur->next = (*pos)->next;
	(*pos)->next = cur;

}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode** pos)
{
	assert(*pos != NULL);
	SListNode* cur = (*pos)->next;
	(*pos)->next = (*pos)->next->next;
	free(cur);
	cur = NULL;

}
// 单链表的销毁
void SListDestroy(SListNode** pplist)
{
	assert(*pplist != NULL);
	SListNode *cur = *pplist;
	SListNode* tmp = cur;
	while (cur != NULL)
	{
		tmp = tmp->next;
		free(cur);
		cur = tmp;
	}
}