//typedef struct {
//    char* key;
//    int val;
//    UT_hash_handle hh;
//} HashItem;
//
//HashItem* hashFindItem(HashItem** obj, char* key) {
//    HashItem* pEntry = NULL;
//    HASH_FIND_STR(*obj, key, pEntry);
//    return pEntry;
//}
//
//bool hashAddItem(HashItem** obj, char* key, int val) {
//    if (hashFindItem(obj, key)) {
//        return false;
//    }
//    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
//    pEntry->key = key;
//    pEntry->val = val;
//    HASH_ADD_STR(*obj, key, pEntry);
//    return true;
//}
//
//bool hashSetItem(HashItem** obj, char* key, int val) {
//    HashItem* pEntry = hashFindItem(obj, key);
//    if (!pEntry) {
//        hashAddItem(obj, key, val);
//    }
//    else {
//        pEntry->val = val;
//    }
//    return true;
//}
//
//int hashGetItem(HashItem** obj, char* key, int defaultVal) {
//    HashItem* pEntry = hashFindItem(obj, key);
//    if (!pEntry) {
//        return defaultVal;
//    }
//    return pEntry->val;
//}
//
//void hashFree(HashItem** obj) {
//    HashItem* curr = NULL, * tmp = NULL;
//    HASH_ITER(hh, *obj, curr, tmp) {
//        HASH_DEL(*obj, curr);
//        free(curr);
//    }
//}
//
//static int cmp(const void* pa, const void* pb) {
//    return strlen(*(char**)pa) - strlen(*(char**)pb);
//}
//
//int longestStrChain(char** words, int wordsSize) {
//    HashItem* cnt = NULL;
//    qsort(words, wordsSize, sizeof(char*), cmp);
//    int res = 0;
//    for (int i = 0; i < wordsSize; i++) {
//        hashAddItem(&cnt, words[i], 1);
//        char prev[32];
//        for (int j = 0; words[i][j] != '\0'; j++) {
//            strcpy(prev + j, words[i] + j + 1);
//            if (hashFindItem(&cnt, prev)) {
//                int len = hashGetItem(&cnt, prev, 0) + 1;
//                int cur = hashGetItem(&cnt, words[i], 0);
//                if (len > cur) {
//                    hashSetItem(&cnt, words[i], len);
//                }
//            }
//            prev[j] = words[i][j];
//        }
//        int cur = hashGetItem(&cnt, words[i], 0);
//        if (cur > res) {
//            res = cur;
//        }
//    }
//    hashFree(&cnt);
//    return res;
//}