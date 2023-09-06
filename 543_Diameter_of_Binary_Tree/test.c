/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getDep(struct TreeNode* root, int* sum) {
    if (root == NULL) {
        return 0;
    }
    int left = getDep(root->left, sum);
    int right = getDep(root->right, sum);
    int max = fmax(left, right);
    *sum = fmax(*sum, (left + right));
    return max + 1;
}
int diameterOfBinaryTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    int sum = 0;
    getDep(root, &sum);
    return sum;
}
