### 160.相交链表

给你两个单链表的头节点 `headA` 和 `headB` ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 `null` 。

来源：力扣

https://leetcode.cn/problems/intersection-of-two-linked-lists/



思路：

​	如果两个链表存在相交节点，两个链表的最后一个节点一定相等，因此先判断尾节点是否相等；

​	在尾节点相同的条件下，要寻找相交的起始节点，需要完成以下几步：

		- 先明确两链表的长度，将链表长度差记为`gap`，指向较长链表的指针记为`longList`，指向较短链表的指针记为`shortList`；
		- `longList`先向前走`gap`步；
		- `longList`和`shortList`同时向前走，步速为1，当两个指针指向的节点的`val`相等时（地址相等），遍历结束，返回`longList`即可。

