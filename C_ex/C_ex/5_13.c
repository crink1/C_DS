#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findMaxK(int* nums, int numsSize) {
    int k = -1;
    for (int i = 0; i < numsSize; i++) {
        int pos = -1;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == -nums[i]) {
                pos = j;
                break;
            }
        }
        if (pos != -1) {
            k = MAX(k, nums[i]);
        }
    }
    return k;
}
