### 198.打家劫舍

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，**如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警**。

给定一个代表每个房屋存放金额的非负整数数组，计算你 **不触动警报装置的情况下** ，一夜之内能够偷窃到的最高金额。

来源：力扣

https://leetcode.cn/problems/house-robber/



思路：

​		构建`dp[numsSize]`，`dp[i]`代表到第`i+1`户为止，能够偷窃到的最高金额。如果`numsSize`为1，直接返回`nums[0]`即可。

​		首先初始化`dp[numsSize]`中所有元素都为0。

​		`dp[0]`本身就应该为0，`dp[1]`表示有两户，选择一户进行偷盗，需要选择出两户中现金多的那一个：`dp[1]=fmax(nums[0], nums[1])`。

​		通过变量i来遍历整个`nums`数组，当`i>=2`时，状态转移方程为`dp[i] = fmax(dp[i-1],dp[i-2]+nums[i])`。

​		最终返回结果应该为`dp[numsSize-1]`。
