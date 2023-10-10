### 106.从中序遍历和后续遍历构造二叉树

给定两个整数数组 `inorder` 和 `postorder` ，其中 `inorder` 是二叉树的中序遍历， `postorder` 是同一棵树的后序遍历，请你构造并返回这颗 *二叉树* 。

来源：力扣

https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/



思路：

​	定义函数`dfs`，用于完成二叉树的构造。首先根据中序遍历和后序遍历的特点，找到中序遍历中根节点的位置，记为`i`，执行 `node->left = dfs(inorder,postorder,begin1,i,begin2,i)`， `node->right = dfs(inorder,postorder,begin1+i+1,l1-i-1,begin2+i,l1-i-1)`。最终返回`node`即可。`buildTree`函数调用`dfs`函数即可。