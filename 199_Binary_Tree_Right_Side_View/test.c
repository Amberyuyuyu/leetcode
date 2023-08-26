/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int* ret = NULL;
int n = 0;

int Depth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return fmax(Depth(root->left), Depth(root->right)) + 1;
}

void f(struct TreeNode* node, int depth) {
    if (node == NULL) {
        return;
    }
    if (depth == n) {
        ret[n++] = node->val;
    }
    f(node->right, depth + 1);
    f(node->left, depth + 1);
}
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    ret = (int*)malloc(sizeof(int) * (Depth(root)));
    n = 0;
    f(root, 0);
    *returnSize = n;
    return ret;
}