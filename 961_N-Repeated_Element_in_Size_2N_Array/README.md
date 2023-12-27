### 961.在长度2N的数组中找出重复N次的元素

给你一个整数数组 `nums` ，该数组具有以下属性：

- `nums.length == 2 * n`.
- `nums` 包含 `n + 1` 个 **不同的** 元素
- `nums` 中恰有一个元素重复 `n` 次

找出并返回重复了 `n` 次的那个元素。

来源：力扣

https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/



思路：

​		定义一个unordered_map类型的变量`countMap`，遍历整个数组，借助`countMap`统计出现过的元素和出现次数。定义`N=nums.size()/2`，遍历`countMap`，如果`kv.second==N`，返回`kv.first`。