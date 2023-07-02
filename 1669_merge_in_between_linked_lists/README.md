### 1669.合并两个链表

给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。

请你将 list1 中下标从 a 到 b 的全部节点都删除，并将list2 接在被删除节点的位置。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/merge-in-between-linked-lists

思路：

​		定义`cur1`和`cur2`两个指针，分别初始化为`list1`和`list2`。

​		通过`cur1`遍历链表1，同时用`count`记录节点个数，目的是找到`a`位置和`b`位置对应的节点，记录`a`位置的前一个节点`prev`，记录`b`的后一个节点`next`。

​		通过`cur2`遍历链表2，将`cur2`指向链表2的最后一个节点。

​		然后通过以下操作链接两个链表：

```
			prev->next = list2;
			cur2->next = next;
```

​		最后返回`list1`即可。