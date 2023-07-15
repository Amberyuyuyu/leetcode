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
void _postOrder(struct TreeNode* root, int* a, int* pi) {
    if (root == NULL) {
        return;
    }
    _postOrder(root->left, a, pi);
    _postOrder(root->right, a, pi);
    a[(*pi)++] = root->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = TreeSize(root);
    int* arr = (int*)malloc(sizeof(int) * size);
    *returnSize = size;
    int i = 0;
    _postOrder(root, arr, &i);

    return arr;
}