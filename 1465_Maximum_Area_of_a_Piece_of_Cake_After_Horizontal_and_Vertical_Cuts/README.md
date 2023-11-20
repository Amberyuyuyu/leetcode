### 1465.切割后面积最大的蛋糕

矩形蛋糕的高度为 `h` 且宽度为 `w`，给你两个整数数组 `horizontalCuts` 和 `verticalCuts`，其中：

-  `horizontalCuts[i]` 是从矩形蛋糕顶部到第 `i` 个水平切口的距离
- `verticalCuts[j]` 是从矩形蛋糕的左侧到第 `j` 个竖直切口的距离

请你按数组 *`horizontalCuts`* 和 *`verticalCuts`* 中提供的水平和竖直位置切割后，请你找出 **面积最大** 的那份蛋糕，并返回其 **面积** 。由于答案可能是一个很大的数字，因此需要将结果 **对** `109 + 7` **取余** 后返回。

来源：力扣

https://leetcode.cn/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

思路：

​		在`horizontalCuts`中`push_back`两个数字：0和`h`，在`verticalCuts`数组中`push_back`两个数字：0和`w`。将这两个数组都进行升序排序，定义`x`和`y`，用于存放最大的高和宽。

​		遍历两个数组， `x = max(x,horizontalCuts[i]-horizontalCuts[i-1])`，`y = max(y,verticalCuts[i]-verticalCuts[i-1])`。

​		最终返回值为`((long long)x*y)%mod`。