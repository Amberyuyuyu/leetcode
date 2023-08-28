/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int x = root->val;
    if (p->val < x && q->val < x) {
        return lowestCommonAncestor(root->left, p, q);
    }
    if (p->val > x && q->val > x) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}