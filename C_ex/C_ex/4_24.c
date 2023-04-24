//#define MAX(a, b) ((a) > (b) ? (a) : (b))
//
//char* lastSubstring(char* s) {
//    int i = 0, j = 1, n = strlen(s);
//    while (j < n) {
//        int k = 0;
//        while (j + k < n && s[i + k] == s[j + k]) {
//            k++;
//        }
//        if (j + k < n && s[i + k] < s[j + k]) {
//            int t = i;
//            i = j;
//            j = MAX(j + 1, t + k + 1);
//        }
//        else {
//            j = j + k + 1;
//        }
//    }
//    char* res = (char*)calloc(n - i + 1, sizeof(char));
//    strncpy(res, s + i, n - i);
//    return res;
//}