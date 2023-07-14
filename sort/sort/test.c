#include"sort.h"

int main()
{
	int a[] = { 5,7,3,8,1,9,0,4,2,6};
	size_t sz = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, sz);
	//ShellSort(a, sz);
	//BubbleSort(a, sz);
	//SelectSort(a, sz);
	//HeapSort(a, sz);
	//QuickSort(a, 0, sz - 1);
	QuickSortNonR(a, 0, sz - 1);
	sortprint(a, sz);
	return 0;
}