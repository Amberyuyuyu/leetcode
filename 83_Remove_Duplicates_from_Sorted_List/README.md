### 83.删除排序链表中的重复元素

给定一个已排序的链表的头 `head` ， *删除所有重复的元素，使每个元素只出现一次* 。返回 *已排序的链表* 。

来源：力扣

https://leetcode.cn/problems/remove-duplicates-from-sorted-list/



思路：

​		首先判断链表是否为空，为空直接返回`head`即可。

​		定义指针`cur`，初始化为指向`head`。当`cur->next`不为空时，遍历整个链表。遇到`cur->val==cur->next->val`的情况时，直接将`cur->next`置为`cur->next->next`，否则`cur = cur->next`。

​	最后返回`head`。