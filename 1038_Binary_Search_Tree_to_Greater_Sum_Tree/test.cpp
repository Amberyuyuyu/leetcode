/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int s = 0;
    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        dfs(node->right);
        s += node->val;
        node->val = s;
        dfs(node->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;

    }
};