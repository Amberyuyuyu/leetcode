### 134.加油站

在一条环路上有 `n` 个加油站，其中第 `i` 个加油站有汽油 `gas[i]` 升。

你有一辆油箱容量无限的的汽车，从第 `i` 个加油站开往第 `i+1` 个加油站需要消耗汽油 `cost[i]` 升。你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 `gas` 和 `cost` ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 `-1` 。如果存在解，则 **保证** 它是 **唯一** 的。

来源：力扣

https://leetcode.cn/problems/gas-station/



思路：

​	定义变量`curSum`，用于表示当前油量，`totalSum`表示总油量，两者区别在于，`totalSum`是从下标为0处开始算，到达最后一个节点为止，而`curSum`表示从下标0开始，一直相加，遇到`curSum`为0的情况，就从该节点下一个位置开始重新计算（`curSum=0`）。定义变量`start`，用来标记开始的位置。

​	定义变量`i`，用于遍历整个数组。定义变量`diff=gas[i]-cost[i]`，分别在`curSum`和`totalSum`上累加`diff`，判断此时的`curSum`，如果它小于0，就将`curSum`置为0，将`start`置为`i+1`。

​	在遍历结束后，如果`totalSum`小于0，说明不存在某一个位置可以按照顺序环路行驶一周，直接返回-1即可，否则的话，返回`start`。