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
//int minimumIncompatibility(int* nums, int numsSize, int k) {
//    int n = numsSize;
//    HashItem* values = NULL;
//    int dp[1 << n];
//    for (int i = 0; i < (1 << n); i++) {
//        dp[i] = INT_MAX;
//    }
//    dp[0] = 0;
//    int group = n / k;
//
//    for (int mask = 1; mask < (1 << n); mask++) {
//        if (__builtin_popcount(mask) != group) {
//            continue;
//        }
//        int mn = 20, mx = 0;
//        int cur[n + 1];
//        memset(cur, 0, sizeof(cur));
//        for (int i = 0; i < n; i++) {
//            if (mask & (1 << i)) {
//                if (cur[nums[i]] > 0) {
//                    break;
//                }
//                cur[nums[i]] = 1;
//                mn = fmin(mn, nums[i]);
//                mx = fmax(mx, nums[i]);
//            }
//        }
//        int curSize = 0;
//        for (int i = 0; i <= n; i++) {
//            if (cur[i] > 0) {
//                curSize++;
//            }
//        }
//        if (curSize == group) {
//            hashAddItem(&values, mask, mx - mn);
//        }
//    }
//    for (int mask = 0; mask < (1 << n); mask++) {
//        if (dp[mask] == INT_MAX) {
//            continue;
//        }
//        HashItem* seen = NULL;
//        for (int i = 0; i < n; i++) {
//            if ((mask & (1 << i)) == 0) {
//                hashAddItem(&seen, nums[i], i);
//            }
//        }
//        if (HASH_COUNT(seen) < group) {
//            continue;
//        }
//        int sub = 0;
//        for (HashItem* pEntry = seen; pEntry; pEntry = pEntry->hh.next) {
//            sub |= (1 << pEntry->val);
//        }
//        hashFree(&seen);
//        int nxt = sub;
//        while (nxt > 0) {
//            if (hashFindItem(&values, nxt)) {
//                dp[mask | nxt] = fmin(dp[mask | nxt], dp[mask] + hashGetItem(&values, nxt, 0));
//            }
//            nxt = (nxt - 1) & sub;
//        }
//    }
//    hashFree(&values);
//    return (dp[(1 << n) - 1] < INT_MAX) ? dp[(1 << n) - 1] : -1;
//}