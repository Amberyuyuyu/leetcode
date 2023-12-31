/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool _isSymmetric(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) {
        return true;
    }
    if (left == NULL || right == NULL) {
        return false;
    }
    if (left->val != right->val) {
        return false;
    }
    return _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root) {
    return _isSymmetric(root->left, root->right);
}