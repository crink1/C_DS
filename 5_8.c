const int INF = 0x3f3f3f3f;

bool ok(int x, int y, int m, int n, const char **grid) { // 不越界且不在墙上
    return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#';
}

int minPushBox(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int sx, sy, bx, by; // 玩家、箱子的初始位置
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            if (grid[x][y] == 'S') {
                sx = x;
                sy = y;
            } else if (grid[x][y] == 'B') {
                bx = x;
                by = y;
            }
        }
    }
    
    int k = m * m * n * n;
    int d[] = {0, -1, 0, 1, 0};
    int dp[m * n][m * n];
    memset(dp, 0x3f, sizeof(dp));
    int queue[k][2];
    int queue1[k][2];
    dp[sx * n + sy][bx * n + by] = 0; // 初始状态的推动次数为 0
    int head = 0, tail = 0;
    int pos = 0;
    queue[tail][0] = sx * n + sy;
    queue[tail][1] = bx * n + by;
    tail++;
    while (tail != head) {
        pos = 0;
        while (tail != head) {
            int s1 = queue[head][0];
            int b1 = queue[head][1];
            head++;
            int sx1 = s1 / n, sy1 = s1 % n, bx1 = b1 / n, by1 = b1 % n;
            if (grid[bx1][by1] == 'T') { // 箱子已被推到目标处
                return dp[s1][b1];
            }
            for (int i = 0; i < 4; i++) { // 玩家向四个方向移动到另一个状态
                int sx2 = sx1 + d[i], sy2 = sy1 + d[i + 1], s2 = sx2*n+sy2;
                if (!ok(sx2, sy2, m, n, grid)) { // 玩家位置不合法
                    continue;
                }
                if (bx1 == sx2 && by1 == sy2) { // 推动箱子
                    int bx2 = bx1 + d[i], by2 = by1 + d[i + 1], b2 = bx2 * n + by2;
                    if (!ok(bx2, by2, m, n, grid) || dp[s2][b2] <= dp[s1][b1] + 1) { // 箱子位置不合法 或 状态已访问
                        continue;
                    }
                    dp[s2][b2] = dp[s1][b1] + 1;
                    queue1[pos][0] = s2;
                    queue1[pos][1] = b2;
                    pos++;
                } else {
                    if (dp[s2][b1] <= dp[s1][b1]) { // 状态已访问
                        continue;
                    }
                    dp[s2][b1] = dp[s1][b1];
                    queue[tail][0] = s2;
                    queue[tail][1] = b1;
                    tail++;
                }
            }
        }
        memcpy(queue, queue1, sizeof(int) * 2 * pos);
        head = 0;
        tail = pos;
    }
    return -1;
}
