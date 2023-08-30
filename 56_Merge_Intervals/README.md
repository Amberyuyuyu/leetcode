### 56.合并区间

以数组 `intervals` 表示若干个区间的集合，其中单个区间为 `intervals[i] = [starti, endi]` 。请你合并所有重叠的区间，并返回 *一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间* 。

来源：力扣

https://leetcode.cn/problems/merge-intervals/



思路：

​		首先定义函数`cmp`：

```c
int cmp(int** a, int** b){
	return a[0][0]>b[0][0];
}
```
​		通过快排将`intervals`升序排列：`qsort(intervals,intervalsSize,sizeof(intervals[0]),cmp);`

​		通过`malloc`函数初始化`ret`：`int** ret = (int**)malloc(sizeof(int*)*intervalsSize);`

​		通过`malloc`函数初始化`returnColumnSizes`：`*returnColumnSizes = (int*)malloc(sizeof(int)*intervalsSize);`

​		通过变量`i`遍历整个`ret`和`returnColumnSizes`：

```c
			ret[i] = malloc(sizeof(int)*2)
			returnColumnSizes[0][i] = 2
```

​	 `returnColumnSizes`中元素代表的是`ret`第`i`个元素的实际列数。

​	定义变量`count`，用于计算`ret`实际元素个数（区间个数）。

​			通过变量`i`遍历整个`intervals`数组，`i`初始化为0。当`i`为0或者`i>0&&intervals[i][0]>ret[count-1][1]`时，说明`ret`还未存放任何区间，或者`i-1`和i两区间无重叠，直接将`intervals[i]`加入`ret`即可。否则，比较`ret[count-1][1]`和`intervals[i][1]`的大小关系，然后将较大值作为新的`ret[count-1][1]`。

​		最后，`*returnSize=count`，返回结果为`ret`。