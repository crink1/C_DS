//int maxSumDivThree(int* arr, int arrSize)
//{
//    int i = 0, r = 0, sum = 0, r1_min = -1, r1_sec = -1, r2_min = -1, r2_sec = -1, temp1 = 0, temp2 = 0;
//
//    while (i < arrSize)
//    {
//        sum += arr[i];
//        r = arr[i] % 3;
//
//        /* ���ж�3ȡ��Ϊ1����ֵ�У���ȡ��Сֵ�͵ڶ�Сֵ���±꣬���û�У����ǳ�ʼ����-1�� */
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
//        /* ���ж�3ȡ��Ϊ2����ֵ�У���ȡ��Сֵ�͵ڶ�Сֵ���±꣬���û�У����ǳ�ʼ����-1�� */
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
//    /* �ܺ�ֱ���ܹ���3��������ֱ�ӷ��ء� */
//    if (0 == r)
//    {
//        return sum;
//    }
//    /* �ܺͶ�3ȡ��Ϊ1�� */
//    else if (1 == r)
//    {
//        temp1 = (-1 != r1_min) ? arr[r1_min] : -1;
//        temp2 = (-1 != r2_min && -1 != r2_sec) ? (arr[r2_min] + arr[r2_sec]) : -1;
//        /* ����ɾ��һ����3ȡ��Ϊ1����С����Ҳ����ɾ��������3ȡ��Ϊ2����С�����Ա�ѡ���֡� */
//        if (-1 != temp1 && -1 != temp2)
//        {
//            temp1 = (temp1 < temp2) ? temp1 : temp2;
//            return sum - temp1;
//        }
//        /* ֻ�ܼ�ȥһ����3ȡ��Ϊ1����С���� */
//        else if (-1 != temp1)
//        {
//            return sum - temp1;
//        }
//        /* ֻ�ܼ�ȥ������3ȡ��Ϊ2����С���� */
//        else if (-1 != temp2)
//        {
//            return sum - temp2;
//        }
//    }
//    /* �ܺͶ�3ȡ��Ϊ2�� */
//    else
//    {
//        temp1 = (-1 != r1_min && -1 != r1_sec) ? (arr[r1_min] + arr[r1_sec]) : -1;
//        temp2 = (-1 != r2_min) ? arr[r2_min] : -1;
//        /* ����ɾ��һ����3ȡ��Ϊ2����С����Ҳ����ɾ��������3ȡ��Ϊ1����С�����Ա�ѡ���֡� */
//        if (-1 != temp1 && -1 != temp2)
//        {
//            temp2 = (temp1 < temp2) ? temp1 : temp2;
//            return sum - temp2;
//        }
//        /* ֻ�ܼ�ȥ������3ȡ��Ϊ1����С���� */
//        else if (-1 != temp1)
//        {
//            return sum - temp1;
//        }
//        /* ֻ�ܼ�ȥһ����3ȡ��Ϊ2����С���� */
//        else if (-1 != temp2)
//        {
//            return sum - temp2;
//        }
//    }
//
//    /* ������������޷���ȡ����������sum��ֱ�ӷ���0�� */
//    return 0;
//}