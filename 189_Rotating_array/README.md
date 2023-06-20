### 189.轮转数组

给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

来源：力扣

https://leetcode.cn/problems/rotate-array/



思路：

​	这里给出一种空间复杂度为`O(1)`的原地算法解决这个问题。

	1. 首先创建一个翻转函数`rotate_right`，可以将给定的数组进行元素倒置；
	1. 将`k`之前的所有元素看作数组1,通过`rotate_right`函数进行倒置；
	1. 将k之后的所有元素看作数组2,通过`rotate_right`函数进行倒置；
	1. 将整个数组nums通过`rotate_right`函数进行倒置，得到的结果就为最终结果。

​	