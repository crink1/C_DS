//void SLPopFront(SLTNode** pphead)
//{
//	assert(*pphead);
//	SLTNode* tmp = (*pphead)->next;
//	free(*pphead);
//	*pphead = tmp;
//
//}
//static int max(int a, int b) {
//    return a > b ? a : b;
//}
//
//static int min(int a, int b) {
//    return a < b ? a : b;
//}
//
//int dfs(struct TreeNode* root, int mi, int ma) {
//    if (root == NULL) {
//        return 0;
//    }
//    int diff = max(abs(root->val - mi), abs(root->val - ma));
//    mi = min(mi, root->val);
//    ma = max(ma, root->val);
//    diff = max(diff, dfs(root->left, mi, ma));
//    diff = max(diff, dfs(root->right, mi, ma));
//    return diff;
//}
//
//int maxAncestorDiff(struct TreeNode* root) {
//    return dfs(root, root->val, root->val);
//}