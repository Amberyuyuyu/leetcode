### 236.二叉树的最近公共祖先

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



思路：

​	分为以下几种情况：

  1. 当前节点是空节点；		**返回当前节点**

  2. 当前节点是p；                **返回当前节点**

  3. 当前节点是q；                **返回当前节点**

  4. 其他：是否找到p或q

     （1）左右子树都找到；**返回当前节点**

     （2）只有左子树找到；**返回递归左子树的结果**

     （3）只有右子树找到；**返回递归右子树的结果**

     （4）左右子树都未找到。**返回空节点**

​	

​		