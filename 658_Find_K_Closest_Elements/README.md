### 658.找到K个最接近的元素

给定一个 **排序好** 的数组 `arr` ，两个整数 `k` 和 `x` ，从数组中找到最靠近 `x`（两数之差最小）的 `k` 个数。返回的结果必须要是按升序排好的。

整数 `a` 比整数 `b` 更接近 `x` 需要满足：

- `|a - x| < |b - x|` 或者
- `|a - x| == |b - x|` 且 `a < b`



来源：力扣

https://leetcode.cn/problems/find-k-closest-elements/



思路：

​	定义`n=arr.size()`，定义`left=0`，`right=n-k`。当满足`left<right`时，定义`(left+right)>>1`，如果`x-arr[mid]>arr[mid+k]-x`，说明左侧端点的值不够接近，可以设置`left=mid+1`，否则的话，设置`right=mid`。

​		最终返回结果为`vector<int>(arr.begin()+left,arr.begin()+left+k)`。