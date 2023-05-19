#include"Stack.h"

void test()
{
	ST s;
	STInit(&s);
	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);
	STPush(&s, 4);
	STPush(&s, 5);
	STPush(&s, 6);
	STPush(&s, 7);
	STPush(&s, 8);
	while (!STEmpty(&s))
	{
		printf("%d", STTop(&s));
		STPop(&s);
	}
	STDestroy(&s);
}



int main()
{
	test();
	return 0;
}