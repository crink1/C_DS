//bool* camelMatch(char** queries, int queriesSize, char* pattern, int* returnSize) {
//    int n = queriesSize;
//    int m = strlen(pattern);
//    bool* res = (bool*)calloc(n, sizeof(bool));
//    for (int i = 0; i < n; i++) {
//        res[i] = true;
//        int p = 0;
//        for (int j = 0; queries[i][j] != '\0'; j++) {
//            if (p < m && pattern[p] == queries[i][j]) {
//                p++;
//            }
//            else if (isupper(queries[i][j])) {
//                res[i] = false;
//                break;
//            }
//        }
//        if (p < m) {
//            res[i] = false;
//        }
//    }
//    *returnSize = n;
//    return res;
//}