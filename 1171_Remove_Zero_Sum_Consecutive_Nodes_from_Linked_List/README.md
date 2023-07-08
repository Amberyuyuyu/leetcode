### 1171.从链表中删去总和值为0的连续节点

给你一个链表的头节点 `head`，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。

删除完毕后，请你返回最终结果链表的头节点。

 

你可以返回任何满足题目要求的答案。

（注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list



思路：

​		由于头节点也可能会发生变化，因此，定义哨兵位节点`dum`，`dum->next = head`。

​		定义指针`cur`，初始化为`dum`。

​		定义指针`next`，初始化为`dum->next`。

​		定义`int`类型变量`sum`，初始化为0。

​		通过指针`cur`遍历整个链表，因为每个节点与它后面的若干节点的值，组合起来可能值为0。	

​		在cur每向后移动一次，都需要执行如下操作：

```
			next = cur->next;
      sum = 0;
```

​		在内层循环中，需要将`next`向后遍历，同时从`sum`中减去`next->val`，遇到`sum==0`时，需要执行删除操作：`cur->next = next->next`，表示将`cur`后的那个节点到`next`这中间的所有节点全部删除。

​		然后执行`next = next->next`。

​		在`next`到达链表末尾时跳出内层循环。外层循环执行`cur = cur->next`。

​		最终返回结果为`dum->next`。

​			