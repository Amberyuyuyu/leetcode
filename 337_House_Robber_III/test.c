/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max(a,b) (((a)>(b) ? (a) : (b)))
struct subTreeStatus {
    int selected;
    int notSelected;
};
struct subTreeStatus dfs(struct TreeNode* root) {
    if (root == NULL) {
        return (struct subTreeStatus) { 0.0 };
    }
    struct subTreeStatus left = dfs(root->left);
    struct subTreeStatus right = dfs(root->right);
    int selected = root->val + left.notSelected + right.notSelected;
    int notselected = max(left.selected, left.notSelected) + max(right.selected, right.notSelected);
    return (struct subTreeStatus) { selected, notselected };
}
int rob(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    struct subTreeStatus rootStatus = dfs(root);
    return max(rootStatus.selected, rootStatus.notSelected);
}