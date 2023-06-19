//int maxSumDivThree(int* arr, int arrSize)
//{
//    int i = 0, r = 0, sum = 0, r1_min = -1, r1_sec = -1, r2_min = -1, r2_sec = -1, temp1 = 0, temp2 = 0;
//
//    while (i < arrSize)
//    {
//        sum += arr[i];
//        r = arr[i] % 3;
//
//        /* 所有对3取余为1的数值中，获取最小值和第二小值的下标，如果没有，则还是初始化的-1。 */
//        if (1 == r)
//        {
//            if (-1 == r1_min)
//            {
//                r1_min = i;
//            }
//            else if (arr[i] <= arr[r1_min])
//            {
//                r1_sec = r1_min;
//                r1_min = i;
//            }
//            else if (-1 == r1_sec || arr[i] < arr[r1_sec])
//            {
//                r1_sec = i;
//            }
//        }
//
//        /* 所有对3取余为2的数值中，获取最小值和第二小值的下标，如果没有，则还是初始化的-1。 */
//        else if (2 == r)
//        {
//            if (-1 == r2_min)
//            {
//                r2_min = i;
//            }
//            else if (arr[i] <= arr[r2_min])
//            {
//                r2_sec = r2_min;
//                r2_min = i;
//            }
//            else if (-1 == r2_sec || arr[i] < arr[r2_sec])
//            {
//                r2_sec = i;
//            }
//        }
//        i++;
//    }
//
//    r = sum % 3;
//
//    /* 总和直接能够被3整除，即直接返回。 */
//    if (0 == r)
//    {
//        return sum;
//    }
//    /* 总和对3取余为1。 */
//    else if (1 == r)
//    {
//        temp1 = (-1 != r1_min) ? arr[r1_min] : -1;
//        temp2 = (-1 != r2_min && -1 != r2_sec) ? (arr[r2_min] + arr[r2_sec]) : -1;
//        /* 可以删除一个对3取余为1的最小数，也可以删除两个对3取余为2的最小数，对比选哪种。 */
//        if (-1 != temp1 && -1 != temp2)
//        {
//            temp1 = (temp1 < temp2) ? temp1 : temp2;
//            return sum - temp1;
//        }
//        /* 只能减去一个对3取余为1的最小数。 */
//        else if (-1 != temp1)
//        {
//            return sum - temp1;
//        }
//        /* 只能减去两个对3取余为2的最小数。 */
//        else if (-1 != temp2)
//        {
//            return sum - temp2;
//        }
//    }
//    /* 总和对3取余为2。 */
//    else
//    {
//        temp1 = (-1 != r1_min && -1 != r1_sec) ? (arr[r1_min] + arr[r1_sec]) : -1;
//        temp2 = (-1 != r2_min) ? arr[r2_min] : -1;
//        /* 可以删除一个对3取余为2的最小数，也可以删除两个对3取余为1的最小数，对比选哪种。 */
//        if (-1 != temp1 && -1 != temp2)
//        {
//            temp2 = (temp1 < temp2) ? temp1 : temp2;
//            return sum - temp2;
//        }
//        /* 只能减去两个对3取余为1的最小数。 */
//        else if (-1 != temp1)
//        {
//            return sum - temp1;
//        }
//        /* 只能减去一个对3取余为2的最小数。 */
//        else if (-1 != temp2)
//        {
//            return sum - temp2;
//        }
//    }
//
//    /* 其余情况都是无法获取满足条件的sum，直接返回0。 */
//    return 0;
//}