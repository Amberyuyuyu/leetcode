### 19.删除链表的倒数第N个结点

给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

来源：力扣

https://leetcode.cn/problems/remove-nth-node-from-end-of-list/



思路：

​		定义两个指针`slow`和`fast`，定义哨兵位节点`dummy`，`dummy->next = head`。`slow`指针最初初始化为`dummy`，`fast`指针初始化为`head`。

​	`fast`先行`n`步，然后两个指针再一起往前走，当`fast`指向最后一个结点时，`slow`指向的是倒数第`n+1`个节点，这时直接将`slow`的`next`变为`slow->next->next`即可完成对倒数第`n`个节点的删除。