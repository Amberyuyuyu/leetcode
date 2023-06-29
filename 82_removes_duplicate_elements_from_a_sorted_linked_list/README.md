### 82.删除排序链表中的重复元素

给定一个已排序的链表的头 `head` ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

来源：力扣

https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/



思路：

​		因为头节点也可能与后面的元素重复，因此，首先建立一个哨兵位节点`dum`，`dum->next = head`。建立一个新指针`cur`，让`cur = dum`。通过`cur`遍历链表，如果`cur->next`与`cur->next->next`的`val`相同，那么就建立变量`x`来存储这个值，并且通过遍历将`cur->next`以及后面所有`val`等于`x`的节点都进行删除。如果`cur->next`与`cur->next->next`不相等，就将`cur`进行移动，`cur = cur->next`。遍历结束的条件为`cur->next`和`cur->next->next`有一个为`NULL`。

​				