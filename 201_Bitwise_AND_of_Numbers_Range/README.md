### 201.数字范围按位与

给你两个整数 `left` 和 `right` ，表示区间 `[left, right]` ，返回此区间内所有数字 **按位与** 的结果（包含 `left` 、`right` 端点）。

来源：力扣

https://leetcode.cn/problems/bitwise-and-of-numbers-range/



思路：

​		多个数字按位与，其结果中值为1的位绝对不会增加，只有可能减少。

​		多个数字按位与，其结果中值为1的位，在多个数字中的对应位必然也为1。

​		本题只需要寻找这些数字的最长相同前缀，就是按位与的结果。

​		定义`mask`为1<<30，定义变量`ans`，初始化为0，用于存放最终结果。

​		当满足`mask>0&&(left&mask==right==mask)`时，都将`left&mask`这个结果加至`ans`中，然后将`mask`左移一位。