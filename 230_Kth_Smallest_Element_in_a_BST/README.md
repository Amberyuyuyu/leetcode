### 230.二叉搜索树中第K小的元素

给定一个二叉搜索树的根节点 `root` ，和一个整数 `k` ，请你设计一个算法查找其中第 `k` 个最小元素（从 1 开始计数）。

来源：力扣

https://leetcode.cn/problems/kth-smallest-element-in-a-bst/



思路：

​		根据二叉搜索树的特性，它的中序遍历的结果一定是升序排列的。因此定义`inorder`函数，将二叉搜索树升序排列的结果，存入数组`ans`中，取`ans[k-1]`即可。