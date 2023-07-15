### 144.二叉树的前序遍历

给你二叉树的根节点 `root` ，返回它节点值的 **前序** 遍历。



来源：力扣

https://leetcode.cn/problems/binary-tree-preorder-traversal/



思路：

​		构建函数`TreeSize`，求出二叉树的总节点个数`size`，通过`malloc`函数定义一个长度为`size`的数组`arr`。

​		定义整型变量`i`，用于标记数组下标。

​		定义函数`_prevOrder`，用于进行前序遍历，该函数采用了分治思想：

			void _prevOrder(struct TreeNode* root, int* a, int* pi){
	 				if(root==NULL){
	     				return;
	 				}
	 				a[(*pi)++] = root->val;
	 
	 				_prevOrder(root->left,a,pi);
	 				_prevOrder(root->right,a,pi); 
	 		}
 		`*returnSize = size`，最后返回`arr`即可。

​		