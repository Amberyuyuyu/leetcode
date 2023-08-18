### 283.移动零

给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。

**请注意** ，必须在不复制数组的情况下原地对数组进行操作。

来源：力扣

https://leetcode.cn/problems/move-zeroes/



思路：

​		定义`swap`函数，用于交换两个指针指向的数字。

​		定义快慢指针`fast`和`slow`，都初始化为0。当`fast<numsSize`时，如果`nums[fast]`不为0，就通过`swap`函数交换`nums[slow]`和`nums[fast]`，并且将`slow`加1。在循环时无论`nums[fast]`是否大于0，都需要执行`fast++`操作。

