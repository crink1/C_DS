//inline int max(int a, int b) {
//    return a > b ? a : b;
//}
//
//int help(const int* nums, int numsSize, int firstLen, int secondLen) {
//    int suml = 0;
//    for (int i = 0; i < firstLen; i++) {
//        suml += nums[i];
//    }
//    int maxSumL = suml;
//    int sumr = 0;
//    for (int i = firstLen; i < firstLen + secondLen; i++) {
//        sumr += nums[i];
//    }
//    int res = maxSumL + sumr;
//    for (int i = firstLen + secondLen, j = firstLen; i < numsSize; ++i, ++j) {
//        suml += nums[j] - nums[j - firstLen];
//        maxSumL = max(maxSumL, suml);
//        sumr += nums[i] - nums[i - secondLen];
//        res = max(res, maxSumL + sumr);
//    }
//    return res;
//}
//
//int maxSumTwoNoOverlap(int* nums, int numsSize, int firstLen, int secondLen) {
//    return max(help(nums, numsSize, firstLen, secondLen), help(nums, numsSize, secondLen, firstLen));
//}
