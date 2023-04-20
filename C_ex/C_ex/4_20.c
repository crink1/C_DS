//#define MIN(a, b) ((a) < (b) ? (a) : (b))
//
//const int INF = 0x3f3f3f3f;
//
//static int cmp(const void* pa, const void* pb) {
//    return *(int*)pa - *(int*)pb;
//}
//
//int binarySearch(int* arr, int left, int right, int val) {
//    int ret = right + 1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (arr[mid] > val) {
//            ret = mid;
//            right = mid - 1;
//        }
//        else {
//            left = mid + 1;
//        }
//    }
//    return ret;
//}
//
//int min(int a, int b) {
//    return a < b ? a : b;
//}
//
//int makeArrayIncreasing(int* arr1, int arr1Size, int* arr2, int arr2Size) {
//    qsort(arr2, arr2Size, sizeof(int), cmp);
//    int m = 0;
//    for (int i = 0; i < arr2Size; i++) {
//        if (i == 0 || arr2[i] != arr2[i - 1]) {
//            arr2[m++] = arr2[i];
//        }
//    }
//    int n = arr1Size;
//    int dp[n + 1][min(n, m) + 1];
//    memset(dp, 0x3f, sizeof(dp));
//    dp[0][0] = -1;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j <= min(i, m); j++) {
//            /* �����ǰԪ�ش������е����һ��Ԫ�� */
//            if (arr1[i - 1] > dp[i - 1][j]) {
//                dp[i][j] = arr1[i - 1];
//            }
//            if (j > 0 && dp[i - 1][j - 1] != INF) {
//                /* ���ֲ����ϸ���� dp[i - 1][j - 1] ����СԪ�� */
//                int index = binarySearch(arr2, j - 1, m - 1, dp[i - 1][j - 1]);
//                if (index != m) {
//                    dp[i][j] = MIN(dp[i][j], arr2[index]);
//                }
//            }
//            if (i == n && dp[i][j] != INF) {
//                return j;
//            }
//        }
//    }
//    return -1;
//}