### 40.组合总和II

给定一个候选人编号的集合 `candidates` 和一个目标数 `target` ，找出 `candidates` 中所有可以使数字和为 `target` 的组合。

`candidates` 中的每个数字在每个组合中只能使用 **一次** 。

**注意：**解集不能包含重复的组合。

来源：力扣

https://leetcode.cn/problems/combination-sum-ii/



思路：

​		回溯问题。

​		定义全局变量`path`，用于表示某一个数字和为`target`的组合，`pathTop`表示该数组长度。定义全局变量`ans`，表示最终返回结果，`ansTop`表示`ans`长度，`ansSize`用于表示`ans`中每一个数组的长度。

​		借助快排将数组`candidates`进行升序排序，这样做的目的是在遇到前后相同的数字时，通过跳过操作降低算法的时间复杂度。

​		定义函数`backtracking`完成回溯算法。如果遇到`sum==target`时，定义数组`temp`，拷贝此时的`path`，将`temp`存入`ans`中：`ans[ansTop]=temp`， `ansSize[ansTop++]=pathTop`，然后结束本次函数调用。如果`sum>target`，直接结束本次函数调用。当`sum<target`时，从当前`index`开始到`candidatesSize`,如果在`i>index`并且`candidates[i]==candidates[i-1]`的情况下，直接`continue`跳过，以此避免在`ans`中出现完全相同的集合。否则的话，将当前下标对应的数字加入`path`中，也在`sum`中加入该数字，调用`backtracking`函数，此时的`index`变为`i+1`，然后将下标为`i`的数字从数组`path`中移除，在`sum`中也减去该数。

​		