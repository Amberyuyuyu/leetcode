### 104.二叉树的最大深度

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 `[3,9,20,null,null,15,7]`，

```
		3
   / \
  9  20
    /  \
   15   7
```

返回它的最大深度 3 。



来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-depth-of-binary-tree



思路：

​		采用分治思想来解题，如果`root`为`NULL`，就直接返回0，否则应该返回`root->left`和`root->right`两颗子树的最大深度+1：

​		`return root==NULL ? 0 : fmax(maxDepth(root->left),maxDepth(root->right))+1`