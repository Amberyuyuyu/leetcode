### 100.相同的树

给你两棵二叉树的根节点 `p` 和 `q` ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

来源：力扣

https://leetcode.cn/problems/same-tree/description/



思路：

​		首先判断`p`和`q`是否为`NULL`，有一个为`NULL`的话，直接返回`p==q`的结果即可。

​		如果`p`和`q`均不为空，要判断它们是否相等，需要同时判断`p`和`q`两节点的`val`，`p->left`和`q->left`，以及`p->right`和`q->right`。如果三者都相等，说明这两棵树才相等。	