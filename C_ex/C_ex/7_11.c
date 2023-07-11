//long long maxAlternatingSum(int* nums, int numsSize) {
//    long long left = nums[0], right = 0;
//    for (int i = 1; i < numsSize; i++) {
//        long long tmp = left;
//        left = fmax(left, right + nums[i]); //当nums[i]作为偶数下标
//        right = fmax(right, tmp - nums[i]); //当nums[j]作为奇数下标
//    }
//    return left;
//}