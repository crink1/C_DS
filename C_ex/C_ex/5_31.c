//const int INF = 0x3f3f3f3f;
//
//static inline int max(int a, int b) {
//    return a > b ? a : b;
//}
//
//static inline int min(int a, int b) {
//    return a < b ? a : b;
//}
//
//int mctFromLeafValues(int* arr, int arrSize) {
//    int n = arrSize;
//    int dp[n][n];
//    int mval[n][n];
//    memset(dp, 0x3f, sizeof(dp));
//    memset(mval, 0, sizeof(mval));
//    for (int j = 0; j < n; j++) {
//        mval[j][j] = arr[j];
//        dp[j][j] = 0;
//        for (int i = j - 1; i >= 0; i--) {
//            mval[i][j] = max(arr[i], mval[i + 1][j]);
//            for (int k = i; k < j; k++) {
//                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mval[i][k] * mval[k + 1][j]);
//            }
//        }
//    }
//    return dp[0][n - 1];
//}