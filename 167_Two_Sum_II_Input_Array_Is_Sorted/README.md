### 167.两数之和II - 输入有序数组

给你一个下标从 1 开始的整数数组 `numbers` ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 `target` 的两个数。如果设这两个数分别是 `numbers[index1]` 和 `numbers[index2]` ，则 `1 <= index1 < index2 <= numbers.length` 。

以长度为 2 的整数数组 `[index1, index2]` 的形式返回这两个整数的下标 `index1` 和 `index2`。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted

思路：

​		由于数组中元素是非递减的，因此定义两个int类型的变量`s1`和`s2`，分别初始化为0、`numberSize-1`。

​		定义int类型的指针arr，开辟`2*sizeof(int*)`的空间。

​		设置`*returnSize = 2`。

​		符合`s1 < s2`的条件时，遍历数组。如果出现`numbers[s1] + numbers[s2] > target`，就执行`s2--`。如果出现`numbers[s1] + numbers[s2] < target`，就执行`s1++`。如果`numbers[s1] + numbers[s2] == target`，就执行如下操作跳出循环：

	arr[0] = s1+1;
	arr[1] = s2+1;
	break;

​	函数最终返回值为`arr`。