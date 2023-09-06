### 543.二叉树的直径

给你一棵二叉树的根节点，返回该树的 **直径** 。

二叉树的 **直径** 是指树中任意两个节点之间最长路径的 **长度** 。这条路径可能经过也可能不经过根节点 `root` 。

两节点之间路径的 **长度** 由它们之间边数表示。

来源：力扣

https://leetcode.cn/problems/diameter-of-binary-tree/





思路：

​	本题实质是求左右子树最大高度的和。

​	如果`root==NULL`，直接返回`NULL`即可。

​	定义变量`sum`，初始化为0，用于表示二叉树的直径。

​	定义函数`getDep`，用于获取左右子树最大高度和。如果`root==NULL`，就返回0。定义`left`和`right`，分别为`getDep(root->left, sum)`和`getDep(root->right, sum)`。将原先的`sum`和得到的`(left+right)`比较，较大值作为新的`sum`。而此时的树的高度为`max(left, right)+1`。

​		在`getDep`函数中，如果遇到`root==NULL`，说明此时递归遍历到叶子节点了，直接递归返回。将最终得到的`sum`返回，即为树的直径。

​	