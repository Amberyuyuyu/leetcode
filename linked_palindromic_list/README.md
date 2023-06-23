### 剑指offer II 027. 回文链表

给定一个链表的 头节点 `head` ，请判断其是否为回文链表。

如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。

来源：力扣

https://leetcode.cn/problems/aMhZSa/



思路：

​		首先要找到中间节点`middlenode`，使用函数`middleNode()`；

​		从`middlenode`节点开始，作为新链表进行翻转，使用函数`reverseList()`；

​		判断原链表与翻转后的新链表进行比较，比较终点为中间节点`middlenode`，如果两者完全相同的话，返回`true`，否则返回`false`。

​		