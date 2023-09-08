/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0 || inorderSize == 0) {
        return NULL;
    }
    struct TreeNode* ret = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    ret->val = preorder[0];
    int index = 0;
    for (index = 0; index < inorderSize; index++) {
        if (inorder[index] == preorder[0]) {
            break;
        }
    }
    ret->left = buildTree(preorder + 1, index, inorder, index);
    ret->right = buildTree(preorder + index + 1, preorderSize - index - 1, inorder + index + 1, preorderSize - index - 1);
    return ret;
}