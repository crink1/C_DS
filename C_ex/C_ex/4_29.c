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
//bool equalFrequency(char* word) {
//    int charCount[26] = { 0 };
//    int len = strlen(word);
//    for (int i = 0; i < len; i++) {
//        charCount[word[i] - 'a']++;
//    }
//    for (int i = 0; i < 26; i++) {
//        if (charCount[i] == 0) {
//            continue;
//        }
//        charCount[i]--;
//        HashItem* frequency = NULL;
//        for (int j = 0; j < 26; j++) {
//            int freq = charCount[j];
//            if (freq > 0) {
//                hashAddItem(&frequency, freq);
//            }
//        }
//        int total = HASH_COUNT(frequency);
//        hashFree(&frequency);
//        if (total == 1) {
//            return true;
//        }
//        charCount[i]++;
//    }
//    return false;
//}