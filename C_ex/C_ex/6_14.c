////定义哈希表元素结构
//typedef struct {
//    int key;  //键值为经理的编号
//    struct ListNode* list; //指向经理下属的链表头结点
//    UT_hash_handle hh;  //哈希表处理器
//} HashItem;
//
////返回两个整数中的较大值
//static int max(int a, int b) {
//    return a > b ? a : b;
//}
//
////创建新的链表结点
//struct ListNode* listNodeCreat(int val) {
//    struct ListNode* obj = (struct ListNode*)malloc(sizeof(struct ListNode));
//    obj->val = val;
//    obj->next = NULL;
//    return obj;
//}
//
////释放链表内存
//void listFree(struct ListNode* head) {
//    while (head) {
//        struct ListNode* cur = head;
//        head = head->next;
//        free(cur);
//    }
//}
//
////在哈希表中查找元素
//HashItem* hashFindItem(HashItem** obj, int key) {
//    HashItem* pEntry = NULL;
//    HASH_FIND_INT(*obj, &key, pEntry);
//    return pEntry;
//}
//
////添加元素到哈希表中
//bool hashAddItem(HashItem** obj, int key, int val) {
//    HashItem* pEntry = hashFindItem(obj, key);
//    if (pEntry != NULL) { //如果经理已存在于哈希表中
//        struct ListNode* cur = listNodeCreat(val); //创建一个链表结点
//        cur->next = pEntry->list; //将新的结点插入链表中
//        pEntry->list = cur;
//    }
//    else { //如果经理不存在于哈希表中
//        pEntry = (HashItem*)malloc(sizeof(HashItem)); //创建新的哈希表元素
//        pEntry->key = key; //设置键值
//        pEntry->list = listNodeCreat(val); //创建链表头结点
//        HASH_ADD_INT(*obj, key, pEntry); //将元素添加到哈希表中
//    }
//    return true;
//}
//
////获取哈希表元素
//struct ListNode* hashGetItem(HashItem** obj, int key) {
//    HashItem* pEntry = hashFindItem(obj, key);
//    if (!pEntry) {
//        return NULL;
//    }
//    else {
//        return pEntry->list;
//    }
//}
//
////释放哈希表内存
//void hashFree(HashItem** obj) {
//    HashItem* curr = NULL, * tmp = NULL;
//    HASH_ITER(hh, *obj, curr, tmp) {
//        HASH_DEL(*obj, curr);  //从哈希表中删除当前元素
//        listFree(curr->list);  //释放当前元素中链表的内存
//        free(curr);             //释放当前元素的内存
//    }
//}
//
////深度优先遍历
//int dfs(int cur, const int* informTime, HashItem** g) {
//    int res = 0;
//    HashItem* pEntry = hashFindItem(g, cur);
//    if (pEntry) {
//        for (struct ListNode* node = pEntry->list; node; node = node->next) {
//            int neighbor = node->val;
//            res = max(res, dfs(neighbor, informTime, g)); //遍历经理的下属
//        }
//    }
//    return informTime[cur] + res;
//}
//
//int numOfMinutes(int n, int headID, int* manager, int managerSize, int* informTime, int informTimeSize) {
//    HashItem* g = NULL;
//    for (int i = 0; i < n; i++) {
//        hashAddItem(&g, manager[i], i);
//    }
//    int ret = dfs(headID, informTime, &g);
//    return ret;
//}