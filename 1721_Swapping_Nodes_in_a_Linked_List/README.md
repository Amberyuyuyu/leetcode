### 1721.交换链表中的节点

给你链表的头节点 `head` 和一个整数 k 。

交换 链表正数第 `k` 个节点和倒数第 `k` 个节点的值后，返回链表的头节点（链表 从 1 开始索引）。

来源：力扣

https://leetcode.cn/problems/swapping-nodes-in-a-linked-list/

思路：

​		首先定义指针`cur`，用于遍历链表，得到链表长度`len`。

​		如果`len`小于`k`，就直接返回`head`。

​		否则，定义快慢指针`fast`和`slow`，初始化为`head`，快指针先走`k-1`步，将这个节点记为`prev_k`，这就是第`k`个节点。

​		然后`slow`和`fast`同时向后遍历链表，`fast->next`为`NULL`时停止，此时`slow`指向的正是倒数第`k`个节点。定义为next_k。

​		定义`int`类型的变量`tmp`,利用`tmp`交换`prev_k`和`next_k`的`val`。最后返回`head`即可。