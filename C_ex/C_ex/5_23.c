//typedef struct {
//    int key;
//    int val;
//    UT_hash_handle hh;
//} HashItem;
//
//HashItem* hashFindItem(HashItem** obj, int key) {
//    HashItem* pEntry = NULL;
//    HASH_FIND_INT(*obj, &key, pEntry);
//    return pEntry;
//}
//
//bool hashAddItem(HashItem** obj, int key, int val) {
//    if (hashFindItem(obj, key)) {
//        return false;
//    }
//    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
//    pEntry->key = key;
//    pEntry->val = val;
//    HASH_ADD_INT(*obj, key, pEntry);
//    return true;
//}
//
//bool hashSetItem(HashItem** obj, int key, int val) {
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
//int hashGetItem(HashItem** obj, int key, int defaultVal) {
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
//    return ((int*)pb)[0] - ((int*)pa)[0];
//}
//
//int largestValsFromLabels(int* values, int valuesSize, int* labels, int labelsSize, int numWanted, int useLimit) {
//    int n = valuesSize;
//    int arr[n][2];
//    for (int i = 0; i < n; i++) {
//        arr[i][0] = values[i];
//        arr[i][1] = i;
//    }
//    qsort(arr, n, sizeof(arr[0]), cmp);
//
//    int ans = 0, choose = 0;
//    HashItem* cnt = NULL;
//    for (int i = 0; i < n && choose < numWanted; ++i) {
//        int id = arr[i][1];
//        int label = labels[id];
//        if (hashGetItem(&cnt, label, 0) == useLimit) {
//            continue;
//        }
//        ++choose;
//        ans += values[id];
//        hashSetItem(&cnt, label, hashGetItem(&cnt, label, 0) + 1);
//    }
//    hashFree(&cnt);
//    return ans;
//}