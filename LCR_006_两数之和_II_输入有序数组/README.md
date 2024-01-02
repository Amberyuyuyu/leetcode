### LCR 006. 两数之和 II - 输入有序数组

给定一个已按照 **升序排列** 的整数数组 `numbers` ，请你从数组中找出两个数满足相加之和等于目标数 `target` 。

函数应该以长度为 `2` 的整数数组的形式返回这两个数的下标值*。*`numbers` 的下标 **从 0 开始计数** ，所以答案数组应当满足 `0 <= answer[0] < answer[1] < numbers.length` 。

假设数组中存在且只存在一对符合条件的数字，同时一个数字不能使用两次。

来源：力扣

https://leetcode.cn/problems/kLl5u1/



思路：

​		定义变量`left`和`right`，分别用于表示`numbers`数组的左右端点，分别初始化为0和`numbers.size()-1`。定义数组`ret`，用于存放最终结果。

​		当满足`left<right`时，定义`sum = numbers[left]+numbers[right]`，如果此时`sum==target`，直接将`numbers[left]`和`numbers[right]`加入到`ret`中，`break`即可。如果`sum<target`，执行`left++`，否则，执行`right--`。