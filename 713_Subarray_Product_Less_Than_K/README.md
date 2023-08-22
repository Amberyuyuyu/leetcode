### 713.乘积小于K的子数组

给你一个整数数组 `nums` 和一个整数 `k` ，请你返回子数组内所有元素的乘积严格小于 `k` 的连续子数组的数目。

来源：力扣

https://leetcode.cn/problems/subarray-product-less-than-k/



思路：

​		采用滑动窗口的思路来解题。

​		首先定义变量`ret_num`，用于存放最终结果，初始化为0，定义变量`ret`，初始化为1，用于表示乘积。定义变量`left`，初始化为0，表示滑动窗口左端点位置。变量`right`表示右端点位置。

​		使用变量`right`遍历数组，每次都需要执行`ret*=nums[right]`，每次都需要判断此时`ret`是否大于等于`k`，如果是的话，需要执行如下操作来缩小窗口范围：

```c
	while(ret >=k && left<right){
        ret /= nums[left];
        left++;
  }
```

​	判断`ret`小于`k`是否成立，成立的话直接在`ret_num`上加`right-left+1`。

​	最终返回值就是`ret_num`。