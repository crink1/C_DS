//int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    int left = 0;
//    int right = numbersSize - 1;
//    while (left < right)
//    {
//        if (numbers[left] + numbers[right] == target)
//        {
//            ret[0] = left + 1;
//            ret[1] = right + 1;
//            *returnSize = 2;
//            return ret;
//        }
//        else if (numbers[left] + numbers[right] > target)
//        {
//            right--;
//        }
//        else
//        {
//            left++;
//        }
//    }
//    *returnSize = 2;
//    return ret;
//}