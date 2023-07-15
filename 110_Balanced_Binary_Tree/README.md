### 110.平衡二叉树

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

​	一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。



思路：

​		

定义函数`maxDepth`，用于获取二叉树的最大深度：

```
int maxDepth(struct TreeNode* root){
    return root==NULL ? 0 : fmax(maxDepth(root->left),maxDepth(root->right))+1;
}
```

判断一棵树是否为平衡二叉树，需要判断这棵树以及所有子树是否为平衡二叉树。借助`maxDepth`函数，求得`root->left`和`root->right`两棵子树是否为平衡二叉树，以及它们最大深度的差值是否为0或1：

	bool isBalanced(struct TreeNode* root){
			if(root == NULL){
	    	return true;
			}
			int leftDepth = maxDepth(root->left);
			int rightDepth = maxDepth(root->right);
			return abs(leftDepth-rightDepth)<2 && isBalanced(root->left) && isBalanced(root->right);
	}
