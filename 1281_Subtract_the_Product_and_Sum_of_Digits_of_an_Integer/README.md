### 1281.整数的各位积和之差

给你一个整数 `n`，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。

来源：力扣

https://leetcode.cn/problems/subtract-the-product-and-sum-of-digits-of-an-integer/



思路：

​		首先判断给定的数字`n`是否为0，如果为0，直接返回0即可。

​		定义变量`mul`和`sum`，分别初始化为1和0。

​		通过一个`while`循环来计算sum和`mul`，循环条件是`n`不为0。在循环中执行如下操作：

			tmp = n%10;
	    mul *= tmp;
	    sum += tmp;
	    n /= 10;

​		最终返回值为`mul-sum`。