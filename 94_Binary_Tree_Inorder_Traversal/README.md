### 94.二叉树的中序遍历

给定一个二叉树的根节点 `root` ，返回 *它的 **中序** 遍历* 。



来源：力扣

https://leetcode.cn/problems/binary-tree-inorder-traversal/



思路：

​		与二叉树的前序遍历相似，首先定义函数`TreeSize`，得到二叉树总节点个数`size`，通过`malloc`函数定义大小为`size`的数组`arr`。

​	定义整型变量`i`，用于表示数组`arr`的下标。

​	定义函数`_inOrder`，用于实现二叉树的中序遍历，并将结果存入`arr`数组中：

		 void _inOrder(struct TreeNode* root, int* a, int* pi){
	 			if(root==NULL){
	     			return;
	 			}
	 			_inOrder(root->left,a,pi);
			 	a[(*pi)++] = root->val;
	 			_inOrder(root->right,a,pi); 
	 	}
 	最终返回`arr`数组即可。