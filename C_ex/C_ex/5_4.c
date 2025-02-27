//#define MAX(a, b) ((a) > (b) ? (a) : (b))
//
//int lowerBound(const int* arr, int left, int right, int val) {
//    int res = right + 1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (arr[mid] >= val) {
//            res = mid;
//            right = mid - 1;
//        }
//        else {
//            left = mid + 1;
//        }
//    }
//    return res;
//}
//
//int upperBound(const int* arr, int left, int right, int val) {
//    int res = right + 1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (arr[mid] > val) {
//            res = mid;
//            right = mid - 1;
//        }
//        else {
//            left = mid + 1;
//        }
//    }
//    return res;
//}
//
//int maxTotalFruits(int** fruits, int fruitsSize, int* fruitsColSize, int startPos, int k) {
//    int n = fruitsSize;
//    int sum[n + 1];
//    int indices[n];
//    sum[0] = 0;
//    for (int i = 0; i < n; i++) {
//        sum[i + 1] = sum[i] + fruits[i][1];
//        indices[i] = fruits[i][0];
//    }
//    int ans = 0;
//    for (int x = 0; x <= k / 2; x++) {
//        /* 向左走 x 步，再向右走 k - x 步 */
//        int y = k - 2 * x;
//        int left = startPos - x;
//        int right = startPos + y;
//        int start = lowerBound(indices, 0, n - 1, left);
//        int end = upperBound(indices, 0, n - 1, right);
//        ans = MAX(ans, sum[end] - sum[start]);
//        /* 向右走 x 步，再向左走 k - x 步 */
//        y = k - 2 * x;
//        left = startPos - y;
//        right = startPos + x;
//        start = lowerBound(indices, 0, n - 1, left);
//        end = upperBound(indices, 0, n - 1, right);
//        ans = MAX(ans, sum[end] - sum[start]);
//    }
//    return ans;