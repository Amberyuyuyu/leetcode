### 42.接雨水

给定 `n` 个非负整数表示每个宽度为 `1` 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

![image](https://github.com/Amberyuyuyu/leetcode/blob/master/42_Trapping_Rain_Water/42.png)

来源：力扣

https://leetcode.cn/problems/trapping-rain-water/



思路：

​		定义变量`ret`表示下雨之后能够接到的雨水数量，定义数组`pre_max[heightSize]`和`suf_max[heightSize]`，分别表示遍历过程中i位置的左右两端的最大高度。通过变量`i`从左到右得到`pre_max`数组每个元素的值，再从右到左得到`suf_max`每个元素的值，再次从左到右对`height`数组进行遍历，每个位置`i`上可以接到的雨水数量为`fmin(pre_max[i], suf_max[i])-height[i]`。

