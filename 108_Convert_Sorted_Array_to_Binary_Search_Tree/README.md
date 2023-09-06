### 108.将有序数组转换为二叉搜索树

给你一个整数数组 `nums` ，其中元素已经按 **升序** 排列，请你将其转换为一棵 **高度平衡** 二叉搜索树。

**高度平衡** 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

来源：力扣

https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/



思路：

​	采用递归的思路来解题。

​	有序数组，其实可以看作二叉搜索树的中序遍历结果。最中间下标对应的元素为根节点。

​	定义函数`_sortedArrayToBST`，如果传入的`left>right`，就直接返回`NULL`。定义变量`mid=(left+right)/2`，定义根节点`root`，`root->val=nums[mid]`。`root->left=_sortedArrayToBST(nums,left,mid-1)`，`right=_sortedArrayToBST(nums,mid+1,right)`。函数返回值为`root`。

​	在`sortedArrayToBST`函数中，直接调用`_sortedArrayToBST(nums,0,numsSize-1)`即可。

