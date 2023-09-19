### 55.跳跃游戏

给你一个非负整数数组 `nums` ，你最初位于数组的 **第一个下标** 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 `true` ；否则，返回 `false` 。



来源：力扣

https://leetcode.cn/problems/jump-game/



思路：

​		定义变量`cover`，表示覆盖范围，初始化为0。

​		定义变量`i`，用于遍历数组`nums`，`cover=fmax(cover,i+nums[i])`，如果此时`cover>=numsSize-1`返回`true`，表明可以到达最后一个下标。如果可以遍历完整个`nums`，说明无法跳跃到最后一个下标，直接返回`false`。