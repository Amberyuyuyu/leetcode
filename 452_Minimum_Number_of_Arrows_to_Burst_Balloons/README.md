### 452.用最少数量的箭引爆气球

有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 `points` ，其中`points[i] = [xstart, xend]` 表示水平直径在 `xstart` 和 `xend`之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 **完全垂直** 地射出。在坐标 `x` 处射出一支箭，若有一个气球的直径的开始和结束坐标为 `x``start`，`x``end`， 且满足  `xstart ≤ x ≤ x``end`，则该气球会被 **引爆** 。可以射出的弓箭的数量 **没有限制** 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 `points` ，*返回引爆所有气球所必须射出的 **最小** 弓箭数* 。

来源：力扣

https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/



思路：

​		如果`pointsSize==0`，直接返回0即可。

​		借助快排将`points`数组按照左边界升序排列。

​		定义变量`ret`，用于统计最少需要的弓箭数，初始化为1，因为当`pointsSize`不为0时，至少需要一支箭。

​		定义变量`i`，用于遍历整个数组，如果`points[i-1][1]<points[i][0]`,说明前后两个区间无交集，这时需要增加一支箭。如果两个区间存在交集，就将`points[i][i]`赋值为`fmin(points[i-1][1],points[i][1])`。

​		最后返回值为`ret`。