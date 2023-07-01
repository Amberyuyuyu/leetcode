### 382.链表随机节点

给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点 被选中的概率一样 。

实现 `Solution` 类：

`Solution(ListNode head)` 使用整数数组初始化对象。
`int getRandom()` 从链表中随机选择一个节点并返回该节点的值。链表中所有节点被选中的概率相等。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/linked-list-random-node



思路：

​		使用整数数组初始化对象，同时在`Solution`结构体中初始化一个`int`类型的变量`idx`，用来记录`Solution`中存放的节点个数。

​		在初始化时，通过`malloc`函数开辟`Solution`对象`sol`的空间，初始化`idx`为0。通过给定的`head`指针遍历整个链表，将所有节点取值存放在`sol->list`数组中。

​		从链表中随机选择节点并返回该节点的值，可以借助`rand`函数：

​			`obj->list[rand()%(obj->idx)]`

​		`rand()%obj->idx`可以得到一个取值在0~`obj->idx`之间的随机数。