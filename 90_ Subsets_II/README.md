### 90.子集II

给你一个整数数组 `nums` ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 **不能** 包含重复的子集。返回的解集中，子集可以按 **任意顺序** 排列。

来源：力扣

https://leetcode.cn/problems/subsets-ii/



思路：

​		回溯问题。

​		定义全局变量`path`，表示某个子集，`pathTop`代表`path`存放元素个数。定义全局变量`ans`，用于存放最终结果，`ansTop`表示`ans`中子集个数，`ansSize`表示`ans`中每个子集的大小。

​		借助快排将数组`nums`进行升序排序。定义函数`backtracking`，如果`startIndex==numsSize`，函数直接终止。如果`startIndex`<`numsSize`时，定义变量`i`，初始化为`startIndex`，对此时的`nums[i]`进行判断，如果此时`i>startIndex`并且`nums[i]==nums[i-1]`，同时还满足`used[i-1]=false`时，说明此时`ans`中已经存在了包含`nums[i]`的子集，如果再次执行`backtracking(nums,numsSize,i,used)`，会造成`ans`中出现相同子集，这时直接`continue`即可。否则的话，将`nums[i]`加入`path`中，将`used[i]`设置为`true`，调用`backtracking(nums,numsSize,i+1,used)`。然后将`nums[i]`从`path`中移除，将`used[i]`设置为`false`。