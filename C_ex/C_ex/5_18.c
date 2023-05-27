//#include<stdio.h>
//#include<assert.h>
//#include<stdbool.h>
//typedef char STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int Top;
//	int capacity;
//}ST;
//
//void STInit(ST* pst)
//{
//	pst->a = NULL;
//	pst->capacity = 0;
//	pst->Top = 0;
//}
//
//bool STEmpty(ST* pst)
//{
//	assert(pst);
//	return pst->Top == 0;
//}
//
//void STPush(ST* pst, STDataType x)
//{
//	assert(pst);
//	if (pst->Top == pst->capacity)
//	{
//		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
//		if (NULL == tmp)
//		{
//			perror("realloc fail");
//			return;
//		}
//		pst->a = tmp;
//		pst->capacity = newcapacity;
//
//	}
//	pst->a[pst->Top] = x;
//	pst->Top++;
//}
//
//void STPop(ST* pst)
//{
//	assert(pst);
//	assert(!STEmpty(pst));
//	pst->Top--;
//}
//
//STDataType STTop(ST* pst)
//{
//	assert(pst);
//	assert(!STEmpty(pst));
//	return pst->a[pst->Top - 1];
//}
//
//
//int STSize(ST* pst)
//{
//	assert(pst);
//	return pst->Top;
//
//}
//
//void STDestroy(ST* pst)
//{
//	assert(pst);
//	free(pst->a);
//	pst->a = NULL;
//	pst->capacity = 0;
//	pst->Top = 0;
//}
//
//bool isValid(char* s) {
//	ST st;
//	STInit(&st);
//	while (*s != '\0')
//	{
//		if (*s == '(' ||
//			*s == '[' ||
//			*s == '{')
//		{
//			STPush(&st, *s);
//			s++;
//		}
//		else
//		{
//			if (STEmpty(&st))
//			{
//				STDestroy(&st);
//				return false;
//			}
//			if ((*s == ')' && STTop(&st) != '(')
//				|| (*s == '}' && STTop(&st) != '{')
//				|| (*s == ']' && STTop(&st) != '['))
//			{
//				STPop(&st);
//				STDestroy(&st);
//				return false;
//			}
//			else
//			{
//				STPop(&st);
//				s++;
//			}
//		}
//	}
//	bool ret = STEmpty(&st);
//	STDestroy(&st);
//	return true;
//
//}
//
//int main()
//{
//	char a=getchar();
//	puts(isValid(&a));
//	return 0;
//}