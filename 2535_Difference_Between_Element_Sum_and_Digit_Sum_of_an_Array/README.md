### 2535.数组元素与数字和的绝对差

给你一个正整数数组 `nums` 。

- **元素和** 是 `nums` 中的所有元素相加求和。
- **数字和** 是 `nums` 中每一个元素的每一数位（重复数位需多次求和）相加求和。

返回 **元素和** 与 **数字和** 的绝对差。

**注意：**两个整数 `x` 和 `y` 的绝对差定义为 `|x - y|` 。

来源：力扣

https://leetcode.cn/problems/difference-between-element-sum-and-digit-sum-of-an-array/

思路：

​		定义长长整形的变量`sum`和`sum1`，都初始化为0，分别表示元素和、数字和。

​		遍历整个`nums`，每一从都执行`sum+=i`，计算`sum1`的方式如下：

```c
	while(i){
		sum1 += i%10;
    i /= 10;
  }
```

​		最终返回值为`abs(sum-sum1)`。