### 46.全排列

给定一个不含重复数字的数组 `nums` ，返回其 *所有可能的全排列* 。你可以 **按任意顺序** 返回答案。

来源：力扣

https://leetcode.cn/problems/permutations/



思路：

​		回溯问题。

​		定义全局变量`path`，用于表示某一个全排列组合，当`path`这个数组的大小达到`numsSize`时，说明找到了一个全排列组合。定义全局变量`pathTop`，用于表示在寻找组合时，数组中存放的元素个数。定义全局变量`ans`，用于表示最终返回结果。定义全局变量`ansTop`，用于记录最终结果中存放的组合个数。

​		定义函数`backtracking`，完成回溯算法实现。如果`pathTop==numsSize`，直接将此时的`path`添加进`ans`中。如果`pathTop`小于`numsSize`，定义变量`i`，初始化为0，当它满足小于`numsSize`的条件时，判断`used[i]`是否为1，为1的话说明当前`path`中已经使用过该元素，直接`continue`即可，如果还未被使用过，就将其加入`path`，然后将`used[i]`改为1，执行`backtracking(nums,numsSize,used)`，然后进行回溯：`pathTop--`，`used[i]=0`。