### 475.供暖器

冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

在加热器的加热半径范围内的每个房屋都可以获得供暖。

现在，给出位于一条水平线上的房屋 `houses` 和供暖器 `heaters` 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。

**注意**：所有供暖器 `heaters` 都遵循你的半径标准，加热的半径也一样。



来源：力扣

https://leetcode.cn/problems/heaters/



思路：

​		将`houses`和`heaters`都进行升序排列，顺次对每个房子找他和他相邻的前后两个加热器即可。在`heaters`首位分别插入`INT_MIN`和`INT_MAX`，定义变量`r`，初始化为0，用于表示半径。变量`n=heaters.size()`，定义`cur=0`，用于表示供暖器的下标。`i`用于表示房子的下标。当满足`cur<n`时，如果`heaters[cur]>=houses[i]`，就`break`跳出循环，否则的话，执行`cur++`。当找到`houses[i]`右侧的取暖器时，这时确定半径，`r = max(r,min((long long)heaters[cur]-houses[i],(long long)houses[i]-heaters[cur-1]))`。

​		遍历结束后返回`r`，就是最终半径。