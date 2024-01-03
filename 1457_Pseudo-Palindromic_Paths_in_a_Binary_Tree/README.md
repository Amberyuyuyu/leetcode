### 1457.二叉树中的伪回文路径

给你一棵二叉树，每个节点的值为 1 到 9 。我们称二叉树中的一条路径是 「**伪回文**」的，当它满足：路径经过的所有节点值的排列中，存在一个回文序列。

请你返回从根到叶子节点的所有路径中 **伪回文** 路径的数目。

来源：力扣

https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/description/



思路：

​		回文序列有两种：

​		 （1）长度为偶数，每个数字出现偶数次；

​		 （2）长度为奇数，有一个数字出现次数为奇数次，其余数字出现偶数次。

​		利用二进制数`mask`来记录，它的每个比特记录着0和1，如果`mask`中全是0或者只有一个1，都说明这个序列是伪回文序列。

​		如果`root==nullpptr`，直接返回0即可。

​		定义`mask ^= 1 << root->val`，如果`root->left==root->right`，如果此时的`mask`满足`mask&(mask-1)==0`，可以构成伪回文序列。否则的话，返回`pseudoPalindromicPaths(root->left,mask)+pseudoPalindromicPaths(root->right,mask)`。