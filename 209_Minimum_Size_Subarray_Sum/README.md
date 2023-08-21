### 209.长度最小的子数组

给定一个含有 `n` 个正整数的数组和一个正整数 `target` **。**

找出该数组中满足其和 `≥ target` 的长度最小的 **连续子数组** `[numsl, numsl+1, ..., numsr-1, numsr]` ，并返回其长度**。**如果不存在符合条件的子数组，返回 `0` 。

来源：力扣

https://leetcode.cn/problems/minimum-size-subarray-sum/



思路：

​		采用滑动窗口的思路来解题。

​		定义变量`n=len(nums)`，定义`ans=n+1`，用于表示在该数组中满足其和`>=target`的长度最小的连续子数组的长度。定义`s`用于表示在遍历过程中计算出的和，定义变量`left`，初始化为0，用于表示滑动窗口左端点位置。采用`right`遍历数组`nums`：`for right,x in enumerate(nums)`，在遍历过程中每次都需要执行`s+=x`操作。遇到`s>=target`时，就比较此时的`ans`与`right-left+1`的大小关系，然后将两者中较小值作为新的`ans`，这时将滑动窗口向右移动，就需要在`s`基础上减去`nums[left]`，并且将`left`加1。

​		遍历结束后，`ans`如果`<=n`，就说明有符合条件的结果，直接返回`ans`即可，否则返回0。