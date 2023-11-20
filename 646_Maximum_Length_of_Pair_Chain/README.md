### 646.最长数对链

给你一个由 `n` 个数对组成的数对数组 `pairs` ，其中 `pairs[i] = [lefti, righti]` 且 `lefti < righti` 。

现在，我们定义一种 **跟随** 关系，当且仅当 `b < c` 时，数对 `p2 = [c, d]` 才可以跟在 `p1 = [a, b]` 后面。我们用这种形式来构造 **数对链** 。

找出并返回能够形成的 **最长数对链的长度** 。

你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。

来源：力扣

https://leetcode.cn/problems/maximum-length-of-pair-chain/



思路：

​		动态规划。

​		定义`n=pairs.size()`，将`pairs`按照区间左端点升序排列。	定义`dp`数组，长度为`n`，将所有元素初始化为1。利用`i`和`j`遍历整个数组，它们的取值范围分别是[0,n)，[0,i)。如果`pairs[i][0]>pairs[j][1]`，`dp[i]=max(dp[i],dp[ij]+1)`。

​		