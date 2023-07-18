//char* convert(char* s, int numRows)
//{
//    int len = strlen(s);
//    if (len == 0 || numRows == 1)
//    {
//        return s;
//    }
//
//    char* a = (char*)malloc(sizeof(char) * (len + 1));
//    a[len] = '\0';
//    int k = 2 * numRows - 2;
//
//    int n = 0;
//    for (int i = 0; i < numRows; i++)
//    {
//        for (int j = 0; j < len; j++)
//        {
//            if (j % k == i || j % k == k - i)
//            {
//                a[n++] = s[j];
//            }
//        }
//    }
//    return a;
//}