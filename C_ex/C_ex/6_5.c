//int* applyOperations(int* nums, int numsSize, int* returnSize) {
//    for (int i = 0, j = 0; i < numsSize; i++) {
//        if (i + 1 < numsSize && nums[i] == nums[i + 1]) {
//            nums[i] *= 2;
//            nums[i + 1] = 0;
//        }
//        if (nums[i] != 0) {
//            int val = nums[i];
//            nums[i] = nums[j];
//            nums[j] = val;
//            j++;
//        }
//    }
//    *returnSize = numsSize;
//    return nums;
//}