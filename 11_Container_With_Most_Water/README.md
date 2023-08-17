### 11.盛最多水的容器

给定一个长度为 `n` 的整数数组 `height` 。有 `n` 条垂线，第 `i` 条线的两个端点是 `(i, 0)` 和 `(i, height[i])` 。

找出其中的两条线，使得它们与 `x` 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

**说明：**你不能倾斜容器。



来源：力扣

https://leetcode.cn/problems/container-with-most-water/



思路：

​			定义`ret`变量，初始化为0，用于存储最大蓄水量。

​			定义变量`left`和`right`，分别初始化为0和`heightSize-1`。分别代表有最大蓄水量的两条线。

​			遍历整个`height`数组，定义变量`area`，表示`left`到`right`两条线之间的蓄水量：`area = (right-left)*fmin(height[left],height[right])`。比较`area`和`ret`，将较大的值作为新的`ret`，如果此时`height[left]<height[right]`，就向后移动`left`，否则，向前移动`right`。

​			

​			