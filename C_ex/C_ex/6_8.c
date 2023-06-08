//#define MAX(a, b) ((a) > (b) ? (a) : (b))
//#define MIN(a, b) ((a) < (b) ? (a) : (b))
//
//bool isAvailable(const bool** rect, int x, int y, int k) {
//    for (int i = 0; i < k; i++) {
//        for (int j = 0; j < k; j++) {
//            if (rect[x + i][y + j]) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//void fillUp(bool** rect, int x, int y, int k, bool val) {
//    for (int i = 0; i < k; i++) {
//        for (int j = 0; j < k; j++) {
//            rect[x + i][y + j] = val;
//        }
//    }
//}
//
//void dfs(int x, int y, bool** rect, int n, int m, int cnt, int* ans) {
//    if (cnt >= *ans) {
//        return;
//    }
//    if (x >= n) {
//        *ans = cnt;
//        return;
//    }
//    /* 检测下一行 */
//    if (y >= m) {
//        dfs(x + 1, 0, rect, n, m, cnt, ans);
//        return;
//    }
//    /* 如当前已经被覆盖，则直接尝试下一个位置 */
//    if (rect[x][y]) {
//        dfs(x, y + 1, rect, n, m, cnt, ans);
//        return;
//    }
//
//    for (int k = MIN(n - x, m - y); k >= 1 && isAvailable(rect, x, y, k); k--) {
//        /* 将长度为 k 的正方形区域标记覆盖 */
//        fillUp(rect, x, y, k, true);
//        /* 跳过 k 个位置开始检测 */
//        dfs(x, y + k, rect, n, m, cnt + 1, ans);
//        fillUp(rect, x, y, k, false);
//    }
//}
//
//int tilingRectangle(int n, int m) {
//    int ans = MAX(n, m);
//    bool* rect[n];
//    for (int i = 0; i < n; i++) {
//        rect[i] = (bool*)calloc(m, sizeof(bool));
//    }
//    dfs(0, 0, rect, n, m, 0, &ans);
//    for (int i = 0; i < n; i++) {
//        free(rect[i]);
//    }
//    return ans;
//}