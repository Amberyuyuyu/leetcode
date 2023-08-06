### 24.两两交换链表中的节点

​		给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

来源：力扣

https://leetcode.cn/problems/swap-nodes-in-pairs/





思路：

​		如果链表为空或者只有一个节点，直接返回链表即可。

​		由于头节点会发生变化，因此定义哨兵位节点`tmp`，`tmp->next = head`。

​		定义`prev`、`cur`、`next`三个指针，分别初始化为`tmp`，`head`和`head->next`。

​		通过三个指针去遍历整个链表，如果链表节点个数为奇数，那么最后一个节点无需交换。因此遍历的条件是`cur != NULL && cur->next != NULL`。

​		在遍历时，需要执行以下操作以交换节点：

			prev->next = next;
	    cur->next = next->next;
	    next->next = cur;
	    prev = cur;
	    cur = cur->next;
	    if(cur != NULL){
	        next = cur->next;
	    }

​			最终返回`tmp->next`即可。