//int connectTwoGroups(int** cost, int costSize, int* costColSize) {
//    int size1 = costSize, size2 = costColSize[0], m = 1 << size2;
//    int dp[size1 + 1][m];
//    memset(dp, 0x3f, sizeof(dp));
//    dp[0][0] = 0;
//    for (int i = 1; i <= size1; i++) {
//        for (int s = 0; s < m; s++) {
//            for (int k = 0; k < size2; k++) {
//                if ((s & (1 << k)) == 0) {
//                    continue;
//                }
//                dp[i][s] = fmin(dp[i][s], dp[i][s ^ (1 << k)] + cost[i - 1][k]);
//                dp[i][s] = fmin(dp[i][s], dp[i - 1][s] + cost[i - 1][k]);
//                dp[i][s] = fmin(dp[i][s], dp[i - 1][s ^ (1 << k)] + cost[i - 1][k]);
//            }
//        }
//    }
//    return dp[size1][m - 1];
//}