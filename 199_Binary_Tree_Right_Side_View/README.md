### 199.二叉树的右视图

给定一个二叉树的 **根节点** `root`，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

来源：力扣

https://leetcode.cn/problems/binary-tree-right-side-view/description/



思路：

​		如果`root`本身为空，直接返回`NULL`即可。

​		构建全局变量`ret`和`n`。在`rightSideView`函数中，将`ret`初始化指向长度为`Depth(root)`的数组的指针。

​		初始化`n`为0，构建函数`f`，功能是按照高度寻找该位置右视图中看到的数组，并存放入`ret`指向的数组中。

​		在`f`函数中，如果`node==NULL`，直接结束函数。如果传入的`depth`与当前数组的元素个数`n`相等，执行`ret[n++]=node->val`。然后先执行`f(node->right,depth+1)`，再执行`f(node->left,depth+1)`。

​		在`rightSideView`函数中，调用`f`函数：`f(root, 0)`。设置`*returnSize=n`，最后返回`ret`即可。

