### 92.反转链表

给你单链表的头指针 `head` 和两个整数 `left` 和 `right` ，其中 `left <= right` 。请你反转从位置 `left` 到位置 `right` 的链表节点，返回 反转后的链表 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reverse-linked-list-ii

思路：

​		由于`left`位置可能位于头节点，头节点在反转过程中可能会发生改变，因此定义哨兵位节点`dum`，设置`dum->next = head`。

​		通过`count`变量和`cur`指针遍历链表，找到`left`位置的节点`leftNode`，`right`位置的节点`rightNode`。

​		将`leftNode`的前一节点记作`prev`，将`rightNode`的后一节点记作`next`。

​		将`leftNode`开头、`rightNode`结束的链表组成新链表。通过`reverseList`函数将新链表进行翻转，并返回新链表头节点`n1`。

​		将原链表的头尾以及新链表进行连接：

	prev->next = n1;
	struct ListNode* n2 = n1;
	while(n1->next){
	    n1 = n1->next;
	}
	n2 = n1;
	n2->next = next;

​		最终返回`dum->next`即可。