//int* gardenNoAdj(int n, int** paths, int pathsSize, int* pathsColSize, int* returnSize) {
//    int adj[n][3], adjSize[n];
//    memset(adjSize, 0, sizeof(adjSize));
//    for (int i = 0; i < pathsSize; i++) {
//        int x = paths[i][0] - 1;
//        int y = paths[i][1] - 1;
//        adj[x][adjSize[x]++] = y;
//        adj[y][adjSize[y]++] = x;
//    }
//    int* ans = (int*)calloc(sizeof(int), n);
//    for (int i = 0; i < n; i++) {
//        bool colored[5];
//        memset(colored, 0, sizeof(colored));
//        for (int j = 0; j < adjSize[i]; j++) {
//            int vertex = adj[i][j];
//            colored[ans[vertex]] = true;
//        }
//        for (int j = 1; j <= 4; j++) {
//            if (colored[j] == 0) {
//                ans[i] = j;
//                break;
//            }
//        }
//    }
//    *returnSize = n;
//    return ans;
//}