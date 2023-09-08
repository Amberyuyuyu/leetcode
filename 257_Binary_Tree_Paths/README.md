### 257.二叉树的所有路径

给你一个二叉树的根节点 `root` ，按 **任意顺序** ，返回所有从根节点到叶子节点的路径。

**叶子节点** 是指没有子节点的节点。

来源：力扣

https://leetcode.cn/problems/binary-tree-paths/



思路：

​		定义数组`path`和`result`，如果`root`为空，直接返回空数组`result`即可。

​		定义函数`traversal`，首先将`cur.val`放入`path`中，如果此时`cur.left`和`cur.right`都为空，就将`path`数组中元素转为字符串，元素之间用'->'连接，然后将结果存放在`result`中。如果`cur.left`不为空，执行`self.tarversal(cur.left, path, result)`，然后执行`path.pop()`，将放入`path`的`cur`移除。同理，如果`cur.right`不为空时，也执行相同的操作。

​	