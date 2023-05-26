//const int INF = 0x3f3f3f3f;
//
//typedef struct Pair {
//    int first;
//    int second;
//} Pair;
//
//int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
//    if (grid[0][0] == 1) {
//        return -1;
//    }
//
//    int n = gridSize;
//    int dist[n][n];
//    Pair queue[n * n];
//    int head = 0, tail = 0;
//
//    memset(dist, 0x3f, sizeof(dist));
//    queue[tail].first = 0;
//    queue[tail].second = 0;
//    tail++;
//    dist[0][0] = 1;
//    while (head != tail) {
//        int x = queue[head].first;
//        int y = queue[head].second;
//        head++;
//        if (x == n - 1 && y == n - 1) {
//            return dist[x][y];
//        }
//        for (int dx = -1; dx <= 1; dx++) {
//            for (int dy = -1; dy <= 1; dy++) {
//                if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= n) { // Խ��
//                    continue;
//                }
//                if (grid[x + dx][y + dy] == 1 || dist[x + dx][y + dy] <= dist[x][y] + 1) { // ��Ԫ��ֵ��Ϊ 0 ���ѱ�����
//                    continue;
//                }
//                dist[x + dx][y + dy] = dist[x][y] + 1;
//                queue[tail].first = x + dx;
//                queue[tail].second = y + dy;
//                tail++;
//            }
//        }
//    }
//    return -1;
//}
