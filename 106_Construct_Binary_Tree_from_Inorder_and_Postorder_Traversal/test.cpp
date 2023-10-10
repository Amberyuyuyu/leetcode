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
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int begin1, int l1, int begin2, int l2) {
        if (l1 != 0) {
            int rv = postorder[begin2 + l2 - 1];
            TreeNode* node = new TreeNode(rv);
            for (int i = 0; i < l1; i++) {
                if (inorder[begin1 + i] == rv) {
                    node->left = dfs(inorder, postorder, begin1, i, begin2, i);
                    node->right = dfs(inorder, postorder, begin1 + i + 1, l1 - i - 1, begin2 + i, l1 - i - 1);
                    break;
                }
            }
            return node;
        }
        else {
            return NULL;
        }
    }
};