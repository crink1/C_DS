//int maximumSum(int* arr, int arrSize) {
//    int dp0 = arr[0];
//    int dp1 = 0;
//    int res = arr[0];
//    for (int i = 1; i < arrSize; i++)
//    {
//        dp1 = fmax(dp0, dp1 + arr[i]);
//        dp0 = fmax(dp0, 0) + arr[i];
//        res = fmax(res, fmax(dp0, dp1));
//    }
//    return res;
//}