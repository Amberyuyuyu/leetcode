### 1283.使结果不超过阈值的最小除数

给你一个整数数组 `nums` 和一个正整数 `threshold` ，你需要选择一个正整数作为除数，然后将数组里每个数都除以它，并对除法结果求和。

请你找出能够使上述结果小于等于阈值 `threshold` 的除数中 **最小** 的那个。

每个数除以除数后都向上取整，比方说 7/3 = 3 ， 10/2 = 5 。

题目保证一定有解。

来源：力扣

https://leetcode.cn/problems/find-the-smallest-divisor-given-a-threshold/



思路：

​		二分查找。

​		首先定义`l=1`，`r=*max_element(nums.begin(),nums.end())`，定义`ans = -1`，用于存放最终结果。

​		当满足`l<=r`时，定义`mid=l+(r-l)/2`，定义`total=0`，遍历整个数组，每一次都在`total`上加`(num-1)/2+1`。如果满足`total<=threshold`，就设置`ans=mid`，`r=mid-1`。否则，设置`l=mid+1`。

​		