//#define MAX_STR_SIZE 16
//
//const char* country[] = { "", "+*-", "+**-", "+***-" };
//
//char* maskPII(char* s) {
//    char* at = strchr(s, '@');
//    if (at != NULL) {
//        for (int i = 0; s[i] != '\0'; i++) {
//            s[i] = tolower(s[i]);
//        }
//        char* res = (char*)calloc(strlen(s) + 8, sizeof(char));
//        sprintf(res, "%c%s%s", s[0], "*****", at - 1);
//        return res;
//    }
//    char tmp[MAX_STR_SIZE];
//    int pos = 0;
//    for (int i = 0; s[i] != '\0'; i++) {
//        if (isdigit(s[i])) {
//            tmp[pos++] = s[i];
//        }
//    }
//    tmp[pos] = '\0';
//    char* res = (char*)calloc(20, sizeof(char));
//    sprintf(res, "%s%s%s", country[pos - 10], "***-***-", tmp + pos - 4);
//    return res;
//}