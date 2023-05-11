typedef struct {
    int key;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

bool help(const char* s, int k, int mi, int ma) {
    HashItem *st = NULL;
    int t = 0;
    for (int r = 0; s[r] != '\0'; ++r) {
        t = t * 2 + (s[r] - '0');
        if (r >= k) {
            t -= (s[r - k] - '0') << k;
        }
        if (r >= k - 1 && t >= mi && t <= ma) {
            hashAddItem(&st, t);
        }
    }
    int count = HASH_COUNT(st);
    hashFree(&st);
    return count == ma - mi + 1;
}

bool queryString(char * s, int n) {
    int len = strlen(s);
    if (n == 1) {
        return strchr(s, '1') != NULL;
    }
    int k = 30;
    while ((1 << k) >= n) {
        --k;
    }
    if (len < (1 << (k - 1)) + k - 1 || len < n - (1 << k) + k + 1) {
        return false;
    }
    return help(s, k, 1 << (k - 1), (1 << k) - 1) && help(s, k + 1, 1 << k, n);
}
