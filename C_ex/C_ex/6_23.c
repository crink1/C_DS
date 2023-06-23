//int maximumValue(char** strs, int strsSize) {
//
//    int res = 0;
//    int j = 0;
//    for (int i = 0; i < strsSize; i++)
//    {
//        bool flag = true;
//        for (int j = 0; j < strlen(*(strs + i)); j++)
//        {
//            if (*(*(strs + i) + j) >= 'a' && *(*(strs + i) + j) <= 'z')
//            {
//                flag = false;
//                break;
//            }
//
//        }
//        if (flag)
//        {
//            res = fmax(res, atoi(*(strs + i)));
//        }
//        else
//        {
//            res = fmax(res, strlen(*(strs + i)));
//        }
//    }
//    return res;
//
//}