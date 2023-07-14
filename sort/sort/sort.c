#include"sort.h"

void sortprint(int *a,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
}

void swap(int* p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int temp = a[i+1];
		while (end >= 0)
		{
			if (a[end] > temp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = temp;

	}
}


void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[i + gap];
			while (end >= 0)
			{
				if (a[end] > temp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = temp;
			}
		}
	}
}


void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int maxi = 0;
	int mini = 0;
	while (begin <  end)
	{
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		swap(a + maxi, a + end);
		if (end == mini)
		{
			mini = maxi;
		}
		swap(a + mini, a + begin);
		begin++;
		end--;
	}
	
}



void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		else
		{
			if (a[parent] < a[child])
			{
				swap(a + parent, a + child);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
}
void HeapSort(int* a, int n)
{
	//����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	//����
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a, a + i);

		AdjustDwon(a, i, 0);
	}
}

int PartQuickSort1(int* a, int left, int right)
{
	int keyi = left;
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[keyi])
		{
			end--;
		}
		while (begin < end && a[begin] <= a[keyi])
		{
			begin++;
		}
		swap(&a[begin], &a[end]);

	}
	swap(&a[keyi], &a[end]);
	keyi = end;
	return keyi;
}

int PartQuickSort2(int* a, int left, int right)
{
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		
		
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
		
	}
	a[hole] = key;
	return hole;
}

int PartQuickSort3(int* a, int left, int right)
{
	int prev = left;
	int cur = left + 1;
	int keyi = left;
	while(cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	swap(&a[keyi], &a[prev]);
	keyi = prev;
	return keyi;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	int keyi = PartQuickSort3(a, begin, end);

	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1 , end);
	
}

void QuickSortNonR(int* a, int begin, int end)
{
	ST s;
	STInit(&s);
	STPush(&s, end);
	STPush(&s, begin);
	while (!STEmpty(&s))
	{
		int left = STTop(&s);
		STPop(&s);
		int right = STTop(&s);
		STPop(&s);
		int keyi = PartQuickSort1(a, left, right);
		if (left < keyi-1)
		{
			STPush(&s, keyi - 1);
			STPush(&s, left);
		}
		if (right > keyi + 1)
		{
			STPush(&s, right);
			STPush(&s, keyi+1);
		}
	}
	STDestroy(&s);

}