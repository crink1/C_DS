#include"SList.h"

// ��̬����һ���ڵ�
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
// �������ӡ
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
// ������β��
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
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}
// �������βɾ
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
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* tmp = *pplist;
	*pplist = (*pplist)->next;
	free(tmp);
	tmp = NULL;
}
// ���������
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
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode** pos, SLTDateType x)
{
	assert(*pos != NULL);
	SListNode* cur = BuySListNode(x);
	cur->next = (*pos)->next;
	(*pos)->next = cur;

}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode** pos)
{
	assert(*pos != NULL);
	SListNode* cur = (*pos)->next;
	(*pos)->next = (*pos)->next->next;
	free(cur);
	cur = NULL;

}
// �����������
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