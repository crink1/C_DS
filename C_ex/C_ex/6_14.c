////�����ϣ��Ԫ�ؽṹ
//typedef struct {
//    int key;  //��ֵΪ����ı��
//    struct ListNode* list; //ָ��������������ͷ���
//    UT_hash_handle hh;  //��ϣ������
//} HashItem;
//
////�������������еĽϴ�ֵ
//static int max(int a, int b) {
//    return a > b ? a : b;
//}
//
////�����µ�������
//struct ListNode* listNodeCreat(int val) {
//    struct ListNode* obj = (struct ListNode*)malloc(sizeof(struct ListNode));
//    obj->val = val;
//    obj->next = NULL;
//    return obj;
//}
//
////�ͷ������ڴ�
//void listFree(struct ListNode* head) {
//    while (head) {
//        struct ListNode* cur = head;
//        head = head->next;
//        free(cur);
//    }
//}
//
////�ڹ�ϣ���в���Ԫ��
//HashItem* hashFindItem(HashItem** obj, int key) {
//    HashItem* pEntry = NULL;
//    HASH_FIND_INT(*obj, &key, pEntry);
//    return pEntry;
//}
//
////���Ԫ�ص���ϣ����
//bool hashAddItem(HashItem** obj, int key, int val) {
//    HashItem* pEntry = hashFindItem(obj, key);
//    if (pEntry != NULL) { //��������Ѵ����ڹ�ϣ����
//        struct ListNode* cur = listNodeCreat(val); //����һ��������
//        cur->next = pEntry->list; //���µĽ�����������
//        pEntry->list = cur;
//    }
//    else { //������������ڹ�ϣ����
//        pEntry = (HashItem*)malloc(sizeof(HashItem)); //�����µĹ�ϣ��Ԫ��
//        pEntry->key = key; //���ü�ֵ
//        pEntry->list = listNodeCreat(val); //��������ͷ���
//        HASH_ADD_INT(*obj, key, pEntry); //��Ԫ����ӵ���ϣ����
//    }
//    return true;
//}
//
////��ȡ��ϣ��Ԫ��
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
////�ͷŹ�ϣ���ڴ�
//void hashFree(HashItem** obj) {
//    HashItem* curr = NULL, * tmp = NULL;
//    HASH_ITER(hh, *obj, curr, tmp) {
//        HASH_DEL(*obj, curr);  //�ӹ�ϣ����ɾ����ǰԪ��
//        listFree(curr->list);  //�ͷŵ�ǰԪ����������ڴ�
//        free(curr);             //�ͷŵ�ǰԪ�ص��ڴ�
//    }
//}
//
////������ȱ���
//int dfs(int cur, const int* informTime, HashItem** g) {
//    int res = 0;
//    HashItem* pEntry = hashFindItem(g, cur);
//    if (pEntry) {
//        for (struct ListNode* node = pEntry->list; node; node = node->next) {
//            int neighbor = node->val;
//            res = max(res, dfs(neighbor, informTime, g)); //�������������
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