### 226.翻转二叉树

给你一棵二叉树的根节点 `root` ，翻转这棵二叉树，并返回其根节点。

来源：力扣

https://leetcode.cn/problems/invert-binary-tree/



思路：

​		首先判断`root`，如果为`NULL`，直接返回`NULL`即可。

​		然后将`root`的左子树进行翻转：`invertTree(root->left)`，将`root`的右子树进行翻转：`invertTree(root->right)`，然后将两颗子树翻转后的结果进行互换，返回`root`即可。