/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root) {
    return root == NULL ? 0 : fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}