//typedef struct {
//    int key;
//    UT_hash_handle hh;
//} HashItem;
//
//HashItem* hashFindItem(HashItem** obj, int key) {
//    HashItem* pEntry = NULL;
//    HASH_FIND_INT(*obj, &key, pEntry);
//    return pEntry;
//}
//
//bool hashAddItem(HashItem** obj, int key) {
//    if (hashFindItem(obj, key)) {
//        return false;
//    }
//    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
//    pEntry->key = key;
//    HASH_ADD_INT(*obj, key, pEntry);
//    return true;
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
//int* powerfulIntegers(int x, int y, int bound, int* returnSize) {
//    HashItem* set = NULL;
//    int value1 = 1;
//    for (int i = 0; i < 21; i++) {
//        int value2 = 1;
//        for (int j = 0; j < 21; j++) {
//            int value = value1 + value2;
//            if (value <= bound) {
//                hashAddItem(&set, value);
//            }
//            else {
//                break;
//            }
//            value2 *= y;
//        }
//        if (value1 > bound) {
//            break;
//        }
//        value1 *= x;
//    }
//    int n = HASH_COUNT(set);
//    int* res = (int*)malloc(sizeof(int) * n);
//    int pos = 0;
//    for (HashItem* pEntry = set; pEntry != NULL; pEntry = pEntry->hh.next) {
//        res[pos++] = pEntry->key;
//    }
//    hashFree(&set);
//    *returnSize = n;
//    return res;
//}