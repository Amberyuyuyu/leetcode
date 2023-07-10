### 16.最接近的三数之和

​		给你一个长度为 `n` 的整数数组 `nums` 和 一个目标值 `target`。请你从 `nums` 中选出三个整数，使它们的和与 `target` 最接近。

​		返回这三个数的和。

​		假定每组输入只存在恰好一个解。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/3sum-closest



思路：

​		首先利用快排对愿数组进行排序。

​		定义整型变量`ret`，初始化为`nums[0]+nums[1]+nums[2]`。定义`minsum=abs(ret-target)`。

​		如果`numsSize==3`，就直接返回`ret`即可。

​		定义变量`i`，通过`i`遍历数组，截止条件为`i==numsSize-2`。对于新赋值的`i`，当`i>0`时，判断`nums[i]`与`nums[i-1]`是否相等，如果相等，直接通过`continue`跳过`i`即可。

​	定义左右两个指针`left`和`right`，分别初始化为`i+1`、`numsSize-1`。当`left<right`时通过这两个指针遍历`i`之后的所有数组元素。

​	定义`sum=nums[i]+nums[left]+nums[right]`，如果`sum==target`，直接返回`target`即可。如果`sum > target`，执行如下代码：

​	`while(left<right && nums[left]==nums[++left]){}`

​	如果sum<target，则执行如下代码：

​	`while(left<right && nums[right]==nums[--right]){}`

​	如果`abs(sum-target)`小于`minsum`，就执行如下代码：

	   minsum = abs(sum-target);
	   ret = sum;

​	 最终找到最小的`minsum`，返回对应的`ret`即可。