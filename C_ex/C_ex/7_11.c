//long long maxAlternatingSum(int* nums, int numsSize) {
//    long long left = nums[0], right = 0;
//    for (int i = 1; i < numsSize; i++) {
//        long long tmp = left;
//        left = fmax(left, right + nums[i]); //��nums[i]��Ϊż���±�
//        right = fmax(right, tmp - nums[i]); //��nums[j]��Ϊ�����±�
//    }
//    return left;
//}