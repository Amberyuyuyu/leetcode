### 1658.将x减到0的最小操作数

给你一个整数数组 `nums` 和一个整数 `x` 。每一次操作时，你应当移除数组 `nums` 最左边或最右边的元素，然后从 `x` 中减去该元素的值。请注意，需要 **修改** 数组以供接下来的操作使用。

如果可以将 `x` **恰好** 减到 `0` ，返回 **最小操作数** ；否则，返回 `-1` 。

来源：力扣

https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/



思路：

​	定义变量`target=accumulate(nums.begin(),nums.end(),0)-x`，如果`target<0`，直接返回-1即可。

​	定义`ans=-1`，用于表示最终结果。定义变量`left=0`，`right=0`。定义`sum=0`，用于暂存元素的和。定义`n=nums.size()`。当满足`right<n`时，执行`sum+=nums[right]`，当满足`sum>target`时，执行`sum-=nums[left++]`。如果最终`sum==target`，就执行`ans = max(ans,right-left+1)`，原因：根据题意，要找到使`x`为0的最小操作数，也就是求得到`target`的最大操作数。

​	最后判断`ans<0 ? -1 : n-ans`。