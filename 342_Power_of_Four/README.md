### 342.4的幂

给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 `true` ；否则，返回 `false` 。

整数 `n` 是 4 的幂次方需满足：存在整数 `x` 使得 `n == 4x`

来源：力扣

https://leetcode.cn/problems/power-of-four/



思路：

​		如果`n==1`返回`true`即可。

​		如果`1<n<4`，返回`false`即可。

​		当满足`n!=1`时，如果`n%4!=0`，返回`false`，否则，`n/=4`。

​		最终返回`true`。		