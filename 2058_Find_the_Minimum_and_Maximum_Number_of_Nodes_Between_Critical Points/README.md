`2058.找出临界点之间的最小和最大距离`

链表中的 临界点 定义为一个 局部极大值点 或 局部极小值点 。

如果当前节点的值 严格大于 前一个节点和后一个节点，那么这个节点就是一个  局部极大值点 。

如果当前节点的值 严格小于 前一个节点和后一个节点，那么这个节点就是一个  局部极小值点 。

注意：节点只有在同时存在前一个节点和后一个节点的情况下，才能成为一个 局部极大值点 / 极小值点 。

给你一个链表 `head` ，返回一个长度为 2 的数组 `[minDistance, maxDistance]` ，其中 `minDistance` 是任意两个不同临界点之间的最小距离，`maxDistance` 是任意两个不同临界点之间的最大距离。如果临界点少于两个，则返回 [-1，-1] 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points



思路：

​	通过`malloc`函数定义`ret`数组，长度为2，`*returnSize = 2`。

​	定义指针`cur`，初始化为`head`。通过`cur`遍历整个链表，得到链表长度`len`。如果`len`小于等于3，则一定找不到大于等于两个临界点，直接将`ret`的两个元素都置为-1，返回`ret`即可。

​	定义数组`arr[len]`，将链表元素逐个存入数组`arr`中。

​	定义数组`ans[len]`，定义变量`j`，初始化`j`为1。通过`j`来遍历数组`arr`,对于满足临界点条件的`j`存入数组`ans`中：

	if(arr[j]>arr[j-1]&&arr[j]>arr[j+1]){
			ans[count++] = j;
			continue;
	 }
	if(arr[j]<arr[j-1]&&arr[j]<arr[j+1]){
			ans[count++] = j;
	}

​	定义比较函数`cmp`，使用快排对`ans`元素排序：

​		`qsort(ans,count,sizeof(int),cmp);`

​	此时`maxDistance`一定等于`ans[count-1]-ans[0]`。

​	定义`minDistance=len`，通过遍历数组`ans`，找到真正的`minDistance`。然后执行：

		ret[0] = minDistance;
		ret[1] = maxDistance;

​	最终返回`ret`即可。