### 15.三数之和

给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/3sum



思路：

​	这个题与两数之和相似，可以借鉴两数之和的思路。

​	使用`malloc`定义数组`ret`，统计组合个数的元素`count`。

​	如果`numsSize`小于3，直接设置`returnSize=0`，返回空数组`ret`。

​	通过变量`i`遍历整个数组，`i`的取值范围为0~`numsSize-2`。

​	定义左右指针`left`和`right`，分别赋初值`i+1`、`numsSize-1`。

​	定义变量`sum`,赋初值0。

​	利用回调函数将数组`nums`进行非降序排列。

​	当给定`i`时，当`i`为0时，如果此时`nums[i]>0`，说明数组中元素均大于0，此时不可能出现三个数和为0的情况，直接返回空数组`ret`即可。

​	当给定`i`时，`left`和`right`移动的截止条件为`left>=right`。需要对新赋值的i进行判断，		

​		`sum=nums[i]+nums[left]+nums[right]`

​	存在三种情况:

​		`sum>0`时，需要执行`right--`;

​		`sum=0`时，需要定义大小为3的数组`arr`,分别将`nums[i]`、`nums[left]`、`nums[right]`存放。然后将数组`arr`放入数组`ret`中，同时将`count`加1。判断此时`right`是否大于`left`，同时满足`nums[right]==nums[right-1]`，此时将`right`减1。判断此时left是否小于`right`，同时满足`nums[left]==nums[left+1]`，此时将`left--`。执行完上述判断后，还需要执行`left++`和`right--`。

​		`sum<0`时，需要执行`left++`。

​	最终返回数组`ret`即可。

