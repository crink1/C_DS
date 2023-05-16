//#define MAX(a, b) ((a) > (b) ? (a) : (b))
//#define MIN(a, b) ((a) < (b) ? (a) : (b))
//
//int minDifficulty(int* jobDifficulty, int jobDifficultySize, int d) {
//    int n = jobDifficultySize;
//    if (n < d) {
//        return -1;
//    }
//    int dp[n + 1][n];
//    memset(dp, 0x3f, sizeof(dp));
//    int ma = 0;
//    for (int i = 0; i < n; ++i) {
//        ma = MAX(ma, jobDifficulty[i]);
//        dp[0][i] = ma;
//    }
//    for (int i = 1; i < d; ++i) {
//        for (int j = i; j < n; ++j) {
//            ma = 0;
//            for (int k = j; k >= i; --k) {
//                ma = MAX(ma, jobDifficulty[k]);
//                dp[i][j] = MIN(dp[i][j], ma + dp[i - 1][k - 1]);
//            }
//        }
//    }
//    return dp[d - 1][n - 1];
//}