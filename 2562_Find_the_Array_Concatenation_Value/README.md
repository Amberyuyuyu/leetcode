### 2562.找出数组的串联值

给你一个下标从 **0** 开始的整数数组 `nums` 。

现定义两个数字的 **串联** 是由这两个数值串联起来形成的新数字。

- 例如，`15` 和 `49` 的串联是 `1549` 。

`nums` 的 **串联值** 最初等于 `0` 。执行下述操作直到 `nums` 变为空：

- 如果 `nums` 中存在不止一个数字，分别选中 `nums` 中的第一个元素和最后一个元素，将二者串联得到的值加到 `nums` 的 **串联值** 上，然后从 `nums` 中删除第一个和最后一个元素。
- 如果仅存在一个元素，则将该元素的值加到 `nums` 的串联值上，然后删除这个元素。

返回执行完所有操作后 `nums` 的串联值。

来源：力扣

https://leetcode.cn/problems/find-the-array-concatenation-value/



思路：

​		定义长长整形变量`ans`，用于存放最终结果，初始化为0。定义变量`i=0`，`j=nums.size()-1`，分别指向数组的首尾位置。用`i`和`j`遍历数组，在满足`i<j`的条件时，每一次都在`ans`的基础上加`stoi(to_string(nums[i])+to_string(nums[j]))`。

​		如果数组长度为奇数，最后还剩下一个数字未被放入`ans`，此时`i==j`，将该元素加入到`ans`中即可。