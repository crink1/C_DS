//ong long dijkstra(int source, int destination, int** adj_matrix, int n) {
//    // ���ص� dijkstra �㷨
//    // adj_matrix ��һ���ڽӾ���
//    long long dist[n];
//    int used[n];
//    memset(used, 0, sizeof(used));
//    for (int i = 0; i < n; i++) {
//        dist[i] = INT_MAX / 2;
//    }
//    dist[source] = 0;
//
//    for (int round = 0; round < n - 1; ++round) {
//        int u = -1;
//        for (int i = 0; i < n; ++i) {
//            if (!used[i] && (u == -1 || dist[i] < dist[u])) {
//                u = i;
//            }
//        }
//        used[u] = true;
//        for (int v = 0; v < n; ++v) {
//            if (!used[v] && adj_matrix[u][v] != -1) {
//                dist[v] = fmin(dist[v], dist[u] + adj_matrix[u][v]);
//            }
//        }
//    }
//
//    return dist[destination];
//}
//
//int** construct(int** edges, int edgesSize, long long idx, int target, int** adj_matrix) {
//    // ��Ҫ������� idx �ֲ�ͬ�ı�Ȩ���������һ���ڽӾ���
//    for (int i = 0; i < edgesSize; i++) {
//        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
//        if (w != -1) {
//            adj_matrix[u][v] = adj_matrix[v][u] = w;
//        }
//        else {
//            if (idx >= target - 1) {
//                adj_matrix[u][v] = adj_matrix[v][u] = target;
//                idx -= (target - 1);
//            }
//            else {
//                adj_matrix[u][v] = adj_matrix[v][u] = 1 + idx;
//                idx = 0;
//            }
//        }
//    }
//    return adj_matrix;
//}
//
//int** modifiedGraphEdges(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination, int target, int* returnSize, int** returnColumnSizes) {
//    int k = 0;
//    for (int i = 0; i < edgesSize; i++) {
//        if (edges[i][2] == -1) {
//            ++k;
//        }
//    }
//
//    int** adj_matrix = (int**)malloc(sizeof(int*) * n);
//    for (int i = 0; i < n; i++) {
//        adj_matrix[i] = (int*)malloc(sizeof(int) * n);
//        memset(adj_matrix[i], 0xff, sizeof(int) * n);
//    }
//    if (dijkstra(source, destination, construct(edges, edgesSize, 0, target, adj_matrix), n) > target) {
//        for (int i = 0; i < n; i++) {
//            free(adj_matrix[i]);
//        }
//        free(adj_matrix);
//        *returnSize = 0;
//        return NULL;
//    }
//    if (dijkstra(source, destination, construct(edges, edgesSize, (long long)k * (target - 1), target, adj_matrix), n) < target) {
//        for (int i = 0; i < n; i++) {
//            free(adj_matrix[i]);
//        }
//        free(adj_matrix);
//        *returnSize = 0;
//        return NULL;
//    }
//
//    long long left = 0, right = (long long)k * (target - 1), ans = 0;
//    while (left <= right) {
//        long long mid = (left + right) / 2;
//        if (dijkstra(source, destination, construct(edges, edgesSize, mid, target, adj_matrix), n) >= target) {
//            ans = mid;
//            right = mid - 1;
//        }
//        else {
//            left = mid + 1;
//        }
//    }
//
//    for (int i = 0; i < edgesSize; i++) {
//        if (edges[i][2] == -1) {
//            if (ans >= target - 1) {
//                edges[i][2] = target;
//                ans -= (target - 1);
//            }
//            else {
//                edges[i][2] = 1 + ans;
//                ans = 0;
//            }
//        }
//    }
//    *returnSize = edgesSize;
//    *returnColumnSizes = edgesColSize;
//    for (int i = 0; i < n; i++) {
//        free(adj_matrix[i]);
//    }
//    free(adj_matrix);
//    return edges;
//}