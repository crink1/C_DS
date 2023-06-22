//int dfs(int x, int y, int** land, int m, int n) {
//    if (x < 0 || x >= m || y < 0 || y >= n || land[x][y] != 0) {
//        return 0;
//    }
//    land[x][y] = -1;
//    int res = 1;
//    for (int dx = -1; dx <= 1; dx++) {
//        for (int dy = -1; dy <= 1; dy++) {
//            if (dx == 0 && dy == 0) {
//                continue;
//            }
//            res += dfs(x + dx, y + dy, land, m, n);
//        }
//    }
//    return res;
//}
//
//static int cmp(const void* a, const void* b) {
//    return *(int*)a - *(int*)b;
//}
//
//int* pondSizes(int** land, int landSize, int* landColSize, int* returnSize) {
//    int m = landSize, n = landColSize[0];
//    int* res = (int*)calloc(m * n, sizeof(int));
//    int pos = 0;
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (land[i][j] == 0) {
//                res[pos++] = dfs(i, j, land, m, n);
//            }
//        }
//    }
//    qsort(res, pos, sizeof(int), cmp);
//    *returnSize = pos;
//    return res;
//}
