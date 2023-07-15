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
bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return abs(leftDepth - rightDepth) < 2 && isBalanced(root->left) && isBalanced(root->right);
}