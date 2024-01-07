### 1094.拼车

车上最初有 `capacity` 个空座位。车 **只能** 向一个方向行驶（也就是说，**不允许掉头或改变方向**）

给定整数 `capacity` 和一个数组 `trips` ,  `trip[i] = [numPassengersi, fromi, toi]` 表示第 `i` 次旅行有 `numPassengersi` 乘客，接他们和放他们的位置分别是 `fromi` 和 `toi` 。这些位置是从汽车的初始位置向东的公里数。

当且仅当你可以在所有给定的行程中接送所有乘客时，返回 `true`，否则请返回 `false`。

来源：力扣

https://leetcode.cn/problems/car-pooling/



思路：

​		定义一个数组`d[1001]{}`，用于表示每个位置上乘客数目，遍历`trips`数组，定义`num=t[0]`,`from=t[1]`,`to=t[2]`，`d[from]+=num`，`d[to]-=num`。

​		定义`s=0`，用于统计乘客数目，遍历数组`d`，每次都执行`s+=v`，如果`s>capacity`，就返回`false`。