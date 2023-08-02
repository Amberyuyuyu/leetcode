### 822.翻转卡片游戏

在桌子上有 `N` 张卡片，每张卡片的正面和背面都写着一个正数（正面与背面上的数有可能不一样）。

我们可以先翻转任意张卡片，然后选择其中一张卡片。

如果选中的那张卡片背面的数字 `X` 与任意一张卡片的正面的数字都不同，那么这个数字是我们想要的数字。

哪个数是这些想要的数字中最小的数（找到这些数中的最小值）呢？如果没有一个数字符合要求的，输出 0。

其中, `fronts[i]` 和 `backs[i]` 分别代表第 `i` 张卡片的正面和背面的数字。

如果我们通过翻转卡片来交换正面与背面上的数，那么当初在正面的数就变成背面的数，背面的数就变成正面的数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/card-flipping-game



思路：

​		定义数组`hash`，将所有元素都初始化为0，用于存放是否存在`fronts[i]==backs[i]`，存在的话，`hash[fronts[i]]++`。

​		定义变量`min`，初始化为`INT_MAX`。

​		遍历两个数组`fronts`和`backs`，	如果`hash[fronts[i]]==0`，就比较`fronts[i]`和`min`，`min=fmin(fronts[i], min)`。如果`hash[backs[i]]==0`，就比较`backs[i]`和`min`，`min=fmin(backs[i], min)`。