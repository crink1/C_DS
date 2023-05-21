#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"


void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	for (int i = n - 1; i > 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDwon(a, i, 0);

	}
}


//TopK
void CreateNDate()
{
	// дьЪ§Он
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(int k)
{
	const char* file = "data.txt";
	FILE* fin = fopen(file, "r");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}
	int* a;
	int* tmp = (int*)malloc(sizeof(int) * k);
	if (NULL == tmp)
	{
		perror("malloc fail");
		return;
	}
	a = tmp;
	for (int i = 0; i < k; i++)
	{
		fscanf(fin, "%d",&a[i]);
	}
	while (!feof(fin))
	{
		int val = 0;
		fscanf(fin, "%d",&val);
		if (val > a[0])
		{
			a[0] = val;
			AdjustDwon(a, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", a[i]);
	}
}

int main()
{
	/*HP hp;
	HPInit(&hp);*/
	//int a[] = { 65,100,70,32,50,60 };
	/*for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		HPPush(&hp, a[i]);
	}
	HPPop(&hp);
	for (int i = 0; i < HPSize(&hp); i++)
	{
		printf("%d\n", hp.a[i]);
	}
	HPDstroy(&hp);*/
	//HeapSort(a, sizeof(a)/sizeof(a[0]));
	/*for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d\n",a[i]);
	}*/
	//CreateNDate();
	PrintTopK(5);
	return 0;
}

