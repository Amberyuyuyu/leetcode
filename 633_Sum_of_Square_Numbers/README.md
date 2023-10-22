### 633.平方数之和

给定一个非负整数 `c` ，你要判断是否存在两个整数 `a` 和 `b`，使得 `a2 + b2 = c` 。

来源：力扣

https://leetcode.cn/problems/sum-of-square-numbers/



思路：

​		如果`c`为0时，直接返回`true`即可。定义变量`a`，初始化为1，当满足`a<(int)sqrt(c)+1`时，定义`double`类型的变量`b=sqrt(c-a*a)`，如果`b==(int)b`，就说明存在这样的两个数满足条件。如果遍历结束都没有返回值，就返回`false`。

​		`sqrt()`函数返回值为`double`类型。