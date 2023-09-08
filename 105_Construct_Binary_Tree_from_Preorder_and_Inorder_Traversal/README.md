### 105.从前序遍历与中序遍历构造二叉树

给定两个整数数组 `preorder` 和 `inorder` ，其中 `preorder` 是二叉树的**先序遍历**， `inorder` 是同一棵树的**中序遍历**，请构造二叉树并返回其根节点。

来源：力扣

https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/



思路：

​		![image](https://github.com/Amberyuyuyu/leetcode/blob/master/105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal/index.png)

​	如果`preorderSize`和`inorderSize`如果存在为`NULL`的情况，直接返回`NULL`即可。

​	定义结构体指针变量`ret`，`ret->val=preorder[0]`，因为前序遍历首元素一定为二叉树的根节点。然后定义变量`index`，初始化为0，用于找到中序遍历中根节点的位置。由于二叉树中无重复元素存在，因此当`inorder[index]==preorder[0]`时，`index`就是根节点所在位置。此时，在`inorder`数组中，`[0,index)`下标对应的元素就是根节点的左子树，而`(index, inorderSize)`下标所对应的元素，是根节点的右子树。根据前序遍历和中序遍历下标对应关系，根节点左子树元素个数为`index`，右子树元素个数为`preorderSize-index-1`。可以得到：`ret->left=buildTree(preorder+1, index, inorder, index )`，`ret->right=buildTree(preorder+index+1, preorderSize-index-1, inorder+index+1, preorderSize-index-1)`。	

​	最终返回值为`ret`。
