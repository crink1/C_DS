static int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int matrixSum(int** nums, int numsSize, int* numsColSize) {
     int res = 0;
    int m = numsSize;
    int n = numsColSize[0];
    for (int i = 0; i < m; i++) {
        qsort(nums[i], n, sizeof(int), cmp);
    }
    for (int j = 0; j < n; j++) {
        int maxVal = 0;
        for (int i = 0; i < m; i++) {
            maxVal = fmax(maxVal, nums[i][j]);
        }
        res += maxVal;
    }
    return res;
}
