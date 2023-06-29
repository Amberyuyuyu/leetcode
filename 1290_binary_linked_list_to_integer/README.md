### 1290.二进制链表转整数

给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。

请你返回该链表所表示数字的 十进制值 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/convert-binary-number-in-a-linked-list-to-integer

思路：

​		n位二进制转十进制：二进制数，从右向左，每一位依次乘以2的0次方、1次方、......、n-1次方。

​		题目的意思是将链表中的每一个节点都当作二进制数的一位，建立新指针`cur`，`cur = head`，在遍历链表过程中，通过如下操作进行十进制转换：

		ret = ret*2+cur->val;
	  cur = cur->next;

