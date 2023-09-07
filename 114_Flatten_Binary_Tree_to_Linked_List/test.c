/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void flatten(struct TreeNode* root) {
    struct TreeNode* ret = root;
    while (ret) {
        if (ret->left) {
            struct TreeNode* lr = ret->left;
            while (lr->right) {
                lr = lr->right;
            }
            lr->right = ret->right;
            ret->right = ret->left;
            ret->left = NULL;
        }
        ret = ret->right;
    }
}