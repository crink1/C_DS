//#define MIN(a, b) ((a) < (b) ? (a) : (b))
//
//const int INF = 0x3f3f3f3f;
//
//int minNumberOfSemesters(int n, int** relations, int relationsSize, int* relationsColSize, int k) {
//    int dp[1 << n];
//    int need[1 << n];
//    memset(dp, 0x3f, sizeof(dp));
//    memset(need, 0, sizeof(need));
//    for (int i = 0; i < relationsSize; i++) {
//        int x = relations[i][0], y = relations[i][1];
//        need[(1 << (y - 1))] |= 1 << (x - 1);
//    }
//    dp[0] = 0;
//    for (int i = 1; i < (1 << n); ++i) {
//        need[i] = need[i & (i - 1)] | need[i & (-i)];
//        if ((need[i] | i) != i) { // i 中有任意一门课程的前置课程没有完成学习
//            continue;
//        }
//        int valid = i ^ need[i]; // 当前学期可以进行学习的课程集合
//        if (__builtin_popcount(valid) <= k) { // 如果个数小于 k，则可以全部学习，不再枚举子集
//            dp[i] = MIN(dp[i], dp[i ^ valid] + 1);
//        }
//        else { // 否则枚举当前学期需要进行学习的课程集合
//            for (int sub = valid; sub; sub = (sub - 1) & valid) {
//                if (__builtin_popcount(sub) <= k) {
//                    dp[i] = MIN(dp[i], dp[i ^ sub] + 1);
//                }
//            }
//        }
//    }
//    return dp[(1 << n) - 1];
//}