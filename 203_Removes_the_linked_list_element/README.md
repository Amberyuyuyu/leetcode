### 203.移除链表元素

​		给你一个链表的头节点 `head` 和一个整数 `val` ，请你删除链表中所有满足 `Node.val == val` 的节点，并返回 新的头节点 。

来源：力扣

https://leetcode.cn/problems/remove-linked-list-elements/



思路：

​	满足`Node.val == val`的节点，存在两种情况：

   1. 头节点的值为`val`，此时需要改变头节点；

   2. 中间某些节点的值为`val`，需要将前一节点直接指向该节点的后一节点。

      

      

