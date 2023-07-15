/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int TreeSize(struct TreeNode* root) {
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _inOrder(struct TreeNode* root, int* a, int* pi) {
    if (root == NULL) {
        return;
    }
    _inOrder(root->left, a, pi);
    a[(*pi)++] = root->val;
    _inOrder(root->right, a, pi);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = TreeSize(root);
    *returnSize = size;
    int* arr = (int*)malloc(sizeof(int) * size);
    int i = 0;
    _inOrder(root, arr, &i);
    return arr;

}