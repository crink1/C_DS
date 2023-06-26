//int pivotInteger(int n) {
//    int i = 1;
//    int j = n;
//    int leftsum = 0;
//    int rightsum = 0;
//    while (i < j)
//    {
//        if (leftsum <= rightsum)
//        {
//            leftsum += i;
//            i++;
//        }
//        if (rightsum < leftsum)
//        {
//            rightsum += j;
//            j--;
//        }
//
//    }
//    if (leftsum == rightsum)
//    {
//        return i;
//    }
//    else
//    {
//        return -1;
//    }
//}