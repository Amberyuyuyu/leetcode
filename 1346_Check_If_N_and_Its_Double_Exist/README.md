### 1346.检查整数及其两倍数是否存在

给你一个整数数组 `arr`，请你检查是否存在两个整数 `N` 和 `M`，满足 `N` 是 `M` 的两倍（即，`N = 2 * M`）。

更正式地，检查是否存在两个下标 `i` 和 `j` 满足：

- `i != j`
- `0 <= i, j < arr.length`
- `arr[i] == 2 * arr[j]`

来源：力扣

https://leetcode.cn/problems/check-if-n-and-its-double-exist/



思路：

​		定义集合`st`。遍历整个`arr`，如果满足`st.count(i*2) || (i%2==0)&&st.count(i/2)`，就返回`true`，否则的话，将`i`插入`st`。

​		如果可以遍历到数组结束，说明不存在符合条件的两个数，返回`false`。