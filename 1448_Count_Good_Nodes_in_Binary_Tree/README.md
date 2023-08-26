### 1448.统计二叉树中好节点的数目

给你一棵根为 `root` 的二叉树，请你返回二叉树中好节点的数目。

「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。

来源：力扣

https://leetcode.cn/problems/count-good-nodes-in-binary-tree/



思路：

​		定义函数`dfs`，如果`root==NULL`时，直接返回0。

​		定义变量`ret`，初始化为0，用于统计二叉树中好节点的个数。如果`root->val>=path_max`，`ret++`，更新`path_max`的值：`path_max=root->val`。

​		然后分别求出`root->left`和`root->right`两棵子树上的好节点个数，加至`ret`上，最终返回`ret`即可。

​		