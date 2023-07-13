//int PartSort3(int* a, int left, int right)
//{
//	int prev = left;
//	int cur = left + 1;
//	int keyi = left;
//	while (cur <= right)
//	{
//		if (a[cur] < a[keyi])
//		{
//			prev++;
//			if (cur != prev)
//			{
//				swap(&a[prev], &a[cur]);
//			}	
//		}
//		cur++;
//	if (left != prev)
//	{
//		swap(&a[prev], &a[keyi]);
//	}
//	return prev;
//}