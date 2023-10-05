### 50.Pow(x,n)

实现 [pow(*x*, *n*)](https://www.cplusplus.com/reference/valarray/pow/) ，即计算 `x` 的整数 `n` 次幂函数（即，`xn` ）。

来源：力扣

https://leetcode.cn/problems/powx-n/



思路：

​			二分思想递归。

​			如果`n==0`，直接返回1。

​			如果`n==1`，直接返回`x`。

​			如果`n==-1`，直接返回`1/x`。

​			定义`double`类型变量`half`，用于计算`x`的`n/2`次方，定义`double`类型的变量`rest`，用于表示计算`x`的`n%2`次方，最终返回结果为`rest*half*half`。