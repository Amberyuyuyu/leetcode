/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getDep(struct TreeNode* root) {
    return root == NULL ? 0 : 1 + fmax(getDep(root->left), getDep(root->right));
}
struct TreeNode* lcaDeepestLeaves(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    struct TreeNode* cur = root;
    struct TreeNode* res = root;
    while (cur) {
        int left = getDep(cur->left);
        int right = getDep(cur->right);
        if (right == left) {
            res = cur;
            break;
        }
        else if (left > right) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    return res;
}