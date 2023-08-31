### 234.回文链表

给你一个单链表的头节点 `head` ，请你判断该链表是否为回文链表。如果是，返回 `true` ；否则，返回 `false` 。

来源：力扣

https://leetcode.cn/problems/palindrome-linked-list/



思路：

​		定义函数`reverse_list`，用于翻转链表。

​		定义函数`getMid`，用于找到链表中间节点。

​		在函数`isPalindrome`中，首先找到中间节点`mid`，然后将中间节点`mid`开始往后的链表进行翻转，定义翻转后链表头节点为`rev`，如果原链表（从`head`到`mid`）和`rev`每个节点都相等，说明原链表是回文链表，否则返回`false`。