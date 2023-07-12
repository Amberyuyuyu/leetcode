### 1019.链表中的下一个更大节点

给定一个长度为 `n` 的链表 `head`

对于列表中的每个节点，查找下一个 更大节点 的值。也就是说，对于每个节点，找到它旁边的第一个节点的值，这个节点的值 严格大于 它的值。

返回一个整数数组 `answer` ，其中 `answer[i]` 是第 `i` 个节点( 从1开始 )的下一个更大的节点的值。如果第 `i` 个节点没有下一个更大的节点，设置 `answer[i] = 0` 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/next-greater-node-in-linked-list



思路：

​	采用暴力法求解。

​	定义指针`cur`，初始化为`head`。

​	通过`cur`遍历链表，得到链表长度`len`。使用`malloc`函数定义`ret`数组，长度为`len`。

​	再次令`cur = head`，利用`cur`遍历整个链表，定义指针`next = cur->next`。然后执行如下操作，在满足题目给定条件时，将`next->val`存入数组中，如果找不到，就存入0：

	while(next && cur->val >= next->val){
		next = next->next;
	}
	if(next){
		ret[i] = next->val;
	}else{
		ret[i] = 0;
	}
	cur = cur->next;
	i++;

​	最终，`*returnSize = i`，返回值为`ret`。