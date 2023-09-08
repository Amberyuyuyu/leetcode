### 437.路径总和III



给定一个二叉树的根节点 `root` ，和一个整数 `targetSum` ，求该二叉树里节点值之和等于 `targetSum` 的 **路径** 的数目。

**路径** 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。



来源：力扣

https://leetcode.cn/problems/path-sum-iii/



思路：

​		如果`root==NULL`，直接返回0。

​		分为两种情况：计算和的时候带`root->val`，计算和时不带`root->val`。

​		定义函数`_pathSum`，如果`root==NULL`，返回0。否则返回`(root->val==targetSum?1:0)+_pathSum(root->left, targetSum-(long)root->val)+_pathSum(root->right, targetSum-(long)root->val)`。

​		在主函数中返回值应该为`_pathSum(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum)`。

​		