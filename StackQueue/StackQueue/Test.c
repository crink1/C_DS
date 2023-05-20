#include"Stack.h"
#include"queue.h"

void stack()
{
	ST s;
	STInit(&s);
	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);
	STPush(&s, 4);
	STPush(&s, 5);
	printf("%d\nsize=%d\n", 
			STTop(&s),STSize(&s));
	STPush(&s, 6);
	STPush(&s, 7);
	STPush(&s, 8);
	STPop(&s);
	while (!STEmpty(&s))
	{
		printf("%d", STTop(&s));
		STPop(&s);
	}
	STDestroy(&s);
}

void queue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	printf("%d\n%d\nsize=%d\n", 
			QueueFront(&q), QueueBack(&q),QueueSize(&q));
	QueuePop(&q);
	
	while (!QueueEmpty(&q))
	{
		QDataType data = QueueFront(&q);
		QueuePop(&q);
		printf("%d", data);
	}
	QueueDestroy(&q);

}

int main()
{
	queue();
	return 0;
}