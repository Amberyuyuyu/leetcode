### 222.完全二叉树的节点个数

给你一棵 **完全二叉树** 的根节点 `root` ，求出该树的节点个数。

[完全二叉树](https://baike.baidu.com/item/完全二叉树/7773232?fr=aladdin) 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 `h` 层，则该层包含 `1~ 2h` 个节点。

来源：力扣

https://leetcode.cn/problems/count-complete-tree-nodes/



思路：

​		递归。

​		如果`root==NULL`，直接返回0，否则，返回`countNodes(root->left)+countNodes(root->right)+1`。