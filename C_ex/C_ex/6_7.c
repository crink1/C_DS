//static int cmp(const void* pa, const void* pb) {
//    return *(int*)pa - *(int*)pb;
//}
//
//int miceAndCheese(int* reward1, int reward1Size, int* reward2, int reward2Size, int k) {
//    int ans = 0;
//    int n = reward1Size;
//    int diffs[n];
//    for (int i = 0; i < n; i++) {
//        ans += reward2[i];
//        diffs[i] = reward1[i] - reward2[i];
//    }
//    qsort(diffs, n, sizeof(int), cmp);
//    for (int i = 1; i <= k; i++) {
//        ans += diffs[n - i];
//    }
//    return ans;
//}