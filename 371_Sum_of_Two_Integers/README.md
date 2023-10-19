### 371.两整数之和

给你两个整数 `a` 和 `b` ，**不使用** 运算符 `+` 和 `-` ，计算并返回两整数之和。

来源：力扣

https://leetcode.cn/problems/sum-of-two-integers/



思路：

​		如果`a`为0，直接返回`b`，如果b为0，直接返回`a`。定义`sum=a^b`，表示的是不进位的和，定义`carry=(unsigned int)(a&b)<<1`，代表的是进位的数值。在计算`getSum(carry,sum)`即可，是一个递归过程。