//bool check(const int* price, int priceSize, int k, int tastiness) {
//    int prev = INT_MIN >> 1;
//    int cnt = 0;
//    for (int i = 0; i < priceSize; i++) {
//        int p = price[i];
//        if (p - prev >= tastiness) {
//            cnt++;
//            prev = p;
//        }
//    }
//    return cnt >= k;
//}
//
//static inline int cmp(const void* pa, const void* pb) {
//    return *(int*)pa - *(int*)pb;
//}
//
//int maximumTastiness(int* price, int priceSize, int k) {
//    qsort(price, priceSize, sizeof(int), cmp);
//    int left = 0, right = price[priceSize - 1] - price[0];
//    while (left < right) {
//        int mid = (left + right + 1) >> 1;
//        if (check(price, priceSize, k, mid)) {
//            left = mid;
//        }
//        else {
//            right = mid - 1;
//        }
//    }
//    return left;
//}
