//int hardestWorker(int n, int** logs, int logsSize, int* logsColSize) {
//    int ans = logs[0][0], maxcost = logs[0][1];
//    for (int i = 1; i < logsSize; ++i) {
//        int idx = logs[i][0];
//        int cost = logs[i][1] - logs[i - 1][1];
//        if (cost > maxcost || (cost == maxcost && idx < ans)) {
//            ans = idx;
//            maxcost = cost;
//        }
//    }
//    return ans;
//}