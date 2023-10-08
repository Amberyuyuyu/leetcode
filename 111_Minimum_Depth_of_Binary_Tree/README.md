### 111.二叉树的最小深度

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

**说明：**叶子节点是指没有子节点的节点。

来源：力扣

https://leetcode.cn/problems/minimum-depth-of-binary-tree/



思路：

​		递归问题。

​		如果`root`为空，直接返回0即可。如果根节点的左右子树都为空，直接返回1即可。

​		定义`min_depth`，用于表示二叉树的最小深度，初始化为`INT_MAX`。如果根节点左子树不为空，那么`min_depth=min(minDepth(root->left),min_depth)`，如果`root->right!=NULL`，那么`min_depth=min(minDepth(root->right),min_depth)`。

​		最终返回结果为`min_depth+1`。