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
		int flag = 1;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = 0;
				swap(&a[j], &a[j + 1]);
			}
		}
		if (flag)
		{
			break;
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



void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		
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
void HeapSort(int* a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//排序
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a, a + i);

		AdjustDown(a, i, 0);
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

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin == end)
	{
		return;
	}
	if (end - begin + 1 < 10)
	{
		InsertSort(a + begin, end - begin + 1);
		return;
	}
	int mid = (begin + end) / 2;
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1,end, tmp);

	

	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int i = begin;
	while ( begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

// 归并排序递归实现
void MergeSort(int* a, int n)
{

	int* tmp = (int*)malloc(sizeof(int) * n);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);

}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
	}
	int gap = 1;
	
	while (gap < n)
	{
		int j = 0;
		for (int i = 0; i < n; i += gap * 2)
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;

			if (end1 > n-1)
			{
				end1 = n - 1;
				begin2 = n;
				end2 = n - 1;
			}
			else if(begin2 > n-1)
			{
				begin2 = n;
				end2 = n - 1;
			}
			else if (end2 > n - 1)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

		}

		memcpy(a, tmp, sizeof(int) * n);
		gap *= 2;
	}
	free(tmp);
}

// 计数排序
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int range = max - min + 1;

	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		perror("malloc fail");
	}
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int k = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			
			a[k++] = i+min;
		}
	}
	
}
