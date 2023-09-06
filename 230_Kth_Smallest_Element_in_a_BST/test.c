/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int* num, int* ans) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, num, ans);
    ans[(*num)++] = root->val;
    inorder(root->right, num, ans);
}

int kthSmallest(struct TreeNode* root, int k) {
    if (root == NULL) {
        return NULL;
    }
    int num = 0;
    int* ans = (int*)malloc(sizeof(int) * 10000);
    inorder(root, &num, ans);
    return ans[k - 1];
}