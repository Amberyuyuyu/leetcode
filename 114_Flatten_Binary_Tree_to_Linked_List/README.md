### 114.二叉树展开为链表

给你二叉树的根结点 `root` ，请你将它展开为一个单链表：

- 展开后的单链表应该同样使用 `TreeNode` ，其中 `right` 子指针指向链表中下一个结点，而左子指针始终为 `null` 。
- 展开后的单链表应该与二叉树 [**先序遍历**](https://baike.baidu.com/item/先序遍历/6442839?fr=aladdin) 顺序相同。

来源：力扣

https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/



思路：

​	经过观察可以发现，二叉树展开为链表后，一定是前序遍历的顺序去存放的。如果要按照二叉树的存储来理解生成的链表，那就是根节点只有右子树，它的任意子节点都是只有右子树节点。

​	左子树的右叶子节点之后跟的是右子树的根节点。定义结构体指针`ret`，初始化为`root`。当`ret`不为空节点时，如果`ret`有左子树，首先遍历左子树，找到它的右叶子节点，定义为`lr`，将`lr`的右子节点变为`ret->right`：`lr->right = ret->right`，`ret`经过变换后的右子节点为`ret->left`，左节点为空。新的`ret`应该为`ret->right`。

​		