### 57.插入区间

给你一个 **无重叠的** *，*按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

来源：力扣

https://leetcode.cn/problems/insert-interval/description/



思路：

​		定义`left`为新区间的左端点，`right`为新区间的右端点。定义布尔类型变量`placed`，用于表示新区间是否已加入原数组中，初始化为`false`。

​	利用变量i遍历整个`intervals`，定义整形指针变量`interval=intervals[i]`，如果`interval[0]`大于`right`，说明`interval`和`newInterval`无交集，可以直接定义整形指针变量`tmp`，将`left`和`right`存入，然后将`tmp`加入`ret`中：

```c
			int* tmp = (int*)malloc(sizeof(int)*2);
      tmp[0] = left;
      tmp[1] = right;
      (*returnColumnSizes)[*returnSize]=2;
      ret[(*returnSize)++] = tmp;
      placed = true;
```

​	然后定义`tmp`变量，将`interval`存入`ret`中：

```c
			int* tmp = malloc(sizeof(int)*2);
      memcpy(tmp,interval,sizeof(int)*2);
      (*returnColumnSizes)[*returnSize] = 2;
      ret[(*returnSize)++] = tmp;
```

​	如果`interval[1]<left`，也说明`interval`与`newInterval`无交集，直接将`interval`加入`ret`即可:

```c
			int* tmp = malloc(sizeof(int)*2);
      memcpy(tmp,interval,sizeof(int)*2);
      (*returnColumnSizes)[*returnSize] = 2;
      ret[(*returnSize)++] = tmp;
```

​	如果`interval`与`newInterval`有交集时，这时根据当前`interval[0]`和`left`的大小关系，`interval[1]`和`right`的大小关系，确定新的`left`和`right`（取交集）:

```
		left = fmin(left,interval[0]);
		right = fmax(right,interval[1]);
```

​	如果遍历完整个`intervals`后，`placed`仍旧为`false`，直接将`newInterval`放入`ret`尾部即可：

			int* tmp = malloc(sizeof(int) * 2);
	    tmp[0] = left, tmp[1] = right;
	    (*returnColumnSizes)[*returnSize] = 2;
	    ret[(*returnSize)++] = tmp;