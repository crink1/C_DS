//#define MIN(a, b) ((a) < (b) ? (a) : (b))
//
//int** reconstructMatrix(int upper, int lower, int* colsum, int colsumSize, int* returnSize, int** returnColumnSizes) {
//    int n = colsumSize;
//    int sum = 0, two = 0;
//    for (int i = 0; i < n; ++i) {
//        if (colsum[i] == 2) {
//            ++two;
//        }
//        sum += colsum[i];
//    }
//    if (sum != upper + lower || MIN(upper, lower) < two) {
//        *returnSize = 0;
//        return NULL;
//    }
//    upper -= two;
//    lower -= two;
//    int** res = (int**)malloc(sizeof(int*) * 2);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 2);
//    for (int i = 0; i < 2; i++) {
//        res[i] = (int*)calloc(n, sizeof(int));
//        (*returnColumnSizes)[i] = n;
//    }
//    for (int i = 0; i < n; ++i) {
//        if (colsum[i] == 2) {
//            res[0][i] = res[1][i] = 1;
//        }
//        else if (colsum[i] == 1) {
//            if (upper > 0) {
//                res[0][i] = 1;
//                --upper;
//            }
//            else {
//                res[1][i] = 1;
//            }
//        }
//    }
//    *returnSize = 2;
//    return res;
//}