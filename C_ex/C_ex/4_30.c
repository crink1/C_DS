//#define MIN(a, b) ((a) < (b) ? (a) : (b))
//#define MAX(a, b) ((a) > (b) ? (a) : (b))
//
//int* numMovesStones(int a, int b, int c, int* returnSize) {
//    int x = MIN(a, b);
//    int z = MAX(a, b);
//    x = MIN(x, c);
//    z = MAX(z, c);
//    int y = a + b + c - x - z;
//
//    int* res = (int*)malloc(sizeof(int) * 2);
//    res[0] = 2;
//    if ((z - y) == 1 && (y - x) == 1) {
//        res[0] = 0;
//    }
//    else if ((z - y) <= 2 || (y - x) <= 2) {
//        res[0] = 1;
//    }
//    res[1] = (z - x - 2);
//    *returnSize = 2;
//    return res;
//}
