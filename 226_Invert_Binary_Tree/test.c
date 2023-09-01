/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    struct ListNode* left = invertTree(root->left);
    struct ListNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}