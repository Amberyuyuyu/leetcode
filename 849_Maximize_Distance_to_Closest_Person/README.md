### 849.到最近的人的最大距离

给你一个数组 `seats` 表示一排座位，其中 `seats[i] = 1` 代表有人坐在第 `i` 个座位上，`seats[i] = 0` 代表座位 `i` 上是空的（**下标从 0 开始**）。

至少有一个空座位，且至少有一人已经坐在座位上。

亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。

返回他到离他最近的人的最大距离。

来源：力扣

https://leetcode.cn/problems/maximize-distance-to-closest-person/



思路：

​		定义变量`ret`用于存放最终结果，定义变量`left`，用于表示亚历克斯座位左边的人，首先通过遍历`seats`数组，找到第一个`seats[i]!=0`的坐标，就是`left`。当`left<seatsSize`时，找到left之后第一个`seats[i]`不为0的`i`值，就是`right`的值（坐在亚历克斯右边的人），如果`right==seatsSize`，说明在`left`之后没有人坐，直接判断`ret`和`right-left+1`的大小关系，将较大的作为新的`ret`即可。如果`right`仍旧小于`seatsSize`，那么亚历克斯应该坐在`right`和`left`正中间的位置上。此时应该将`ret`和`(right-left)/2`中较大的一个作为新的`ret`。

​		最后返回值为`ret`。