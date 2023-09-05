### 1921.消灭怪物的最大数量

你正在玩一款电子游戏，在游戏中你需要保护城市免受怪物侵袭。给你一个 **下标从 0 开始** 且长度为 `n` 的整数数组 `dist` ，其中 `dist[i]` 是第 `i` 个怪物与城市的 **初始距离**（单位：米）。

怪物以 **恒定** 的速度走向城市。给你一个长度为 `n` 的整数数组 `speed` 表示每个怪物的速度，其中 `speed[i]` 是第 `i` 个怪物的速度（单位：米/分）。

怪物从 **第 0 分钟** 时开始移动。你有一把武器，并可以 **选择** 在每一分钟的开始时使用，包括第 0 分钟。但是你无法在一分钟的中间使用武器。这种武器威力惊人，一次可以消灭任一还活着的怪物。

一旦任一怪物到达城市，你就输掉了这场游戏。如果某个怪物 **恰** 在某一分钟开始时到达城市，这会被视为 **输掉** 游戏，在你可以使用武器之前，游戏就会结束。

返回在你输掉游戏前可以消灭的怪物的 **最大** 数量。如果你可以在所有怪物到达城市前将它们全部消灭，返回 `n` 。

来源：力扣

https://leetcode.cn/problems/eliminate-maximum-number-of-monsters/



思路；

​		首先，根据`dist`数组和`speed`数组得到一个新数据`time_arr`，用于表示每个怪物到达城市需要的时间。如果`dist[i]%speed[i]!=0`，就需要在`dist[i]/speed[i]`的基础上加1。

​		借助快排将`time_arr`升序排列。

​		借助变量i遍历数组`time_arr`，如果`time_arr[i]<=i`，说明无法阻止该怪物进入城市，此时的`i`就是能消灭怪物的最大数量。

​	如果数组成功遍历到结束，就返回数组的长度。说明所有怪物都可以被消灭。
