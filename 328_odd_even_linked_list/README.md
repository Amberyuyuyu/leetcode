328.奇偶链表

给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。

第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。

请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。

你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/odd-even-linked-list



思路：

​		如果链表为空、链表节点个数小于等于2时，直接返回原链表即可。

​		链表第一个节点为奇数节点，用指针`oddHead`来标记，同时建立与`oddHead`完全相同的新指针`oddNode`，第二个节点为偶数节点，用指针`evenHead`来标记，同时建立与`evenHead`完全相同的新指针`evenNode`。创建新节点`cur`，令`cur=evenNode`，也就是利用指针`cur`从第三个节点开始遍历链表。当`cur`为`NULL`时结束。每向后挪动一次，挪动连个节点。新的`cur`就是`oddNode->next`，`cur->next`是`evenNode->next`。在挪动时出现`cur->next == NULL`，就停止遍历，否则，新的`cur`应该为`cur->next->next`。

​		遍历结束后，直接将`evenHead`赋值给`oddNode->next`即可。最终返回值为`oddHead`。
