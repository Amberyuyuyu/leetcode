/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* root, int path_max) {
    if (root == NULL) {
        return 0;
    }
    int ret = 0;
    if (root->val >= path_max) {
        ret++;
        path_max = root->val;
    }
    ret += dfs(root->left, path_max) + dfs(root->right, path_max);
    return ret;
}
int goodNodes(struct TreeNode* root) {
    return dfs(root, INT_MIN);
}