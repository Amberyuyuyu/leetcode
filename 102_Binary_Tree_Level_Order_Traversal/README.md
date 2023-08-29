### 102.二叉树的层序遍历

给你二叉树的根节点 `root` ，返回其节点值的 **层序遍历** 。 （即逐层地，从左到右访问所有节点）。

来源：力扣

https://leetcode.cn/problems/binary-tree-level-order-traversal/description/



思路：

​		如果根节点为空，直接返回[]空数组即可。

​		定义`ans`数组，用于存放最终结果，定义数组`cur`，初始化为`[root]`，用于存放当前层所有的节点。当`cur`不为空时，定义数组`nxt`和数组`vals`。借助变量`node`遍历整个`cur`数组，将所有`node`的`val`值存放进`vals`数组中。将所有`node`节点的左右子树的节点放入`nxt`数组中。然后将`nxt`置为新的`cur`，将`vals`存放入`ans`中。

​	当`cur`数组为空时，证明已经遍历完二叉树的所有层，直接返回`ans`即可。