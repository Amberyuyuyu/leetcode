### 337.打家劫舍III

小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 `root` 。

除了 `root` 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 **两个直接相连的房子在同一天晚上被打劫** ，房屋将自动报警。

给定二叉树的 `root` 。返回 ***在不触动警报的情况下** ，小偷能够盗取的最高金额* 。

来源：力扣

https://leetcode.cn/problems/house-robber-iii/



思路：

​		定义一个结构体`subTreeStatus`，包含两个变量：`selected`和`notSelected`，分别表示是否偷盗该节点。

​		定义函数`dfs`，用于计算从某个节点开始能够偷到的最大金额，返回值为`subTreeStatus`结构体，包含了偷盗当前节点和不偷盗当前节点的最大偷窃金额。如果`root==NULL`，直接返回`(struct subTreeStatus){0.0}`。定义`left=dfs(root->left)`，`right=fmax(root->right)`。`selected=root->val + left.notSelected + right.notSelected`，`notSelected=max(left.selected,left.notSelected)+max(right.selected,right.notSelected)`。最终返回值为`(struct subTreeStatus){selected,notselected}`。

​		在`rob`函数中，如果`root==NULL`，直接返回0即可。否则的话，将`root`传入`dfs`函数，计算选择该节点、不选择该节点时的盗窃最大金额，然后取两者中的最大值作为函数返回值。