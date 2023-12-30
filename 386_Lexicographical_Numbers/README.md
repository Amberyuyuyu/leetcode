### 386.字典序排数

给你一个整数 `n` ，按字典序返回范围 `[1, n]` 内所有整数。

你必须设计一个时间复杂度为 `O(n)` 且使用 `O(1)` 额外空间的算法。

来源：力扣

https://leetcode.cn/problems/lexicographical-numbers/



思路：

​		定义如下的字符串比较函数：

```c
		static bool compareStrings(const string& str1, const string& str2){
    	return str1 < str2;
		} 
```

​		定义字符串数组`arr`，长度为`n`，将1~n的所有数转换为字符串存入`arr`中。按照定义的比较函数对数组进行排序。定义新数组`res`，长度为`n`，遍历`arr`数组中元素，转为数字后存入`res`。