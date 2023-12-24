### 2300.咒语和药水的成功对数

给你两个正整数数组 `spells` 和 `potions` ，长度分别为 `n` 和 `m` ，其中 `spells[i]` 表示第 `i` 个咒语的能量强度，`potions[j]` 表示第 `j` 瓶药水的能量强度。

同时给你一个整数 `success` 。一个咒语和药水的能量强度 **相乘** 如果 **大于等于** `success` ，那么它们视为一对 **成功** 的组合。

请你返回一个长度为 `n` 的整数数组 `pairs`，其中 `pairs[i]` 是能跟第 `i` 个咒语成功组合的 **药水** 数目。

来源：力扣

https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/



思路：

​		定义`n`和`m`分别为`spells`、`potions`的长度，定义数组`ans`，用于存放最终结果。对数组`potions`进行排序，遍历`spells`数组，`ans[i]=positions.end()-lower_bound(potions.begin(),potions.end(),success*1.0/spells[i])`。