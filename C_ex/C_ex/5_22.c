//bool checkSufficientLeaf(struct TreeNode* node, int sum, int limit) {
//    if (!node) {
//        return false;
//    }
//    if (node->left == NULL && node->right == NULL) {
//        return node->val + sum >= limit;
//    }
//    bool haveSufficientLeft = checkSufficientLeaf(node->left, sum + node->val, limit);
//    bool haveSufficientRight = checkSufficientLeaf(node->right, sum + node->val, limit);
//    if (!haveSufficientLeft) {
//        node->left = NULL;
//    }
//    if (!haveSufficientRight) {
//        node->right = NULL;
//    }
//    return haveSufficientLeft || haveSufficientRight;
//}
//
//struct TreeNode* sufficientSubset(struct TreeNode* root, int limit) {
//    bool haveSufficient = checkSufficientLeaf(root, 0, limit);
//    return haveSufficient ? root : NULL;
//}