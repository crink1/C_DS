//#define MAX_NODES 1000
//
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
//struct TreeNode* dfs(struct TreeNode* node, bool is_root, const HashItem* to_delete_set, struct TreeNode** roots, int* pos) {
//    if (node == NULL) {
//        return NULL;
//    }
//    bool deleted = hashFindItem(&to_delete_set, node->val) != NULL ? true : false;
//    node->left = dfs(node->left, deleted, to_delete_set, roots, pos);
//    node->right = dfs(node->right, deleted, to_delete_set, roots, pos);
//    if (deleted) {
//        return NULL;
//    }
//    else {
//        if (is_root) {
//            roots[(*pos)++] = node;
//        }
//        return node;
//    }
//};
//
//struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize) {
//    struct TreeNode** roots = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAX_NODES);
//    int pos = 0;
//    HashItem* to_delete_set = NULL;
//    for (int i = 0; i < to_deleteSize; i++) {
//        hashAddItem(&to_delete_set, to_delete[i]);
//    }
//    dfs(root, true, to_delete_set, roots, &pos);
//    *returnSize = pos;
//    hashFree(&to_delete_set);
//    return roots;
//}