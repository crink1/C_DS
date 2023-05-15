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
//        free(curr->key);
//        free(curr);
//    }
//}
//
//#define MAX(a, b) ((a) > (b) ? (a) : (b))
//
//int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize) {
//    int m = matrixSize, n = matrixColSize[0];
//    HashItem* mp = NULL;
//    for (int i = 0; i < m; i++) {
//        char* s = (char*)calloc(n + 1, sizeof(char));
//        memset(s, '0', sizeof(char) * n);
//        for (int j = 0; j < n; j++) {
//            // ��� matrix[i][0] Ϊ 1����Ը���Ԫ�ؽ��з�ת
//            s[j] = '0' + (matrix[i][j] ^ matrix[i][0]);
//        }
//        hashSetItem(&mp, s, hashGetItem(&mp, s, 0) + 1);
//    }
//    int res = 0;
//    for (HashItem* pEntry = mp; pEntry != NULL; pEntry = pEntry->hh.next) {
//        res = MAX(res, pEntry->val);
//    }
//    hashFree(&mp);
//    return res;
//}