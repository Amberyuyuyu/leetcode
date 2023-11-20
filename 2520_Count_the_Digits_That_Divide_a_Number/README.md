### 2520.统计能整除数字的位数

给你一个整数 `num` ，返回 `num` 中能整除 `num` 的数位的数目。

如果满足 `nums % val == 0` ，则认为整数 `val` 可以整除 `nums` 。

来源：力扣

https://leetcode.cn/problems/count-the-digits-that-divide-a-number/



思路：

​	定义`ans`用于存放最终结果，初始化为0，定义`x=num`，当满足`x>0`时，`ans += num%(x%10)==0`，每次都执行`x/=10`。		