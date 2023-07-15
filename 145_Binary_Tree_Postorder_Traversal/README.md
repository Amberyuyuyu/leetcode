### 145.二叉树的后序遍历

给你一棵二叉树的根节点 `root` ，返回其节点值的 **后序遍历** 。



来源：力扣

https://leetcode.cn/problems/binary-tree-postorder-traversal/





思路：

​		定义后序遍历函数`_postOrder`：

```
 void _postOrder(struct TreeNode* root, int* a, int* pi){
     if(root==NULL){
         return;
     }
     _postOrder(root->left,a,pi);
     _postOrder(root->right,a,pi); 
     a[(*pi)++] = root->val;
 }
```

