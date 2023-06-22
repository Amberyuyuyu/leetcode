### 206.翻转链表

给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表。

来源：力扣

https://leetcode.cn/problems/reverse-linked-list/



思路：

​	有两种解决办法：

1. 通过三个指针遍历整个链表，`n1`初始化为`NULL`，`n2`指向`head`，记录`n2->next`为`n3`，将`n2`的`next`指向前一个节点`n1`，然后将`n2`赋值给`n1`，将`n3`赋值给`n2`，而`n3=n3->next`，当`n2`变为链表最后一个节点时，`n3==NULL`，此时不需要再执行`n3=n3->next`。当`n2`为`NULL`时，链表翻转完成，返回结果为`n1`。这种方法在代码中通过`reverseList_1(struct ListNode* head)`函数来实现；

2. 通过单链表头部插入元素来实现链表翻转。首先作如下定义：

   `struct ListNode* cur = head;`

    `struct ListNode* newhead = NULL;`

   通过`cur`指针遍历整个链表，将`cur->next`定义为`next`。`cur->next=newhead`，然后将`newhead`变为`cur`，`cur=cur->next`，执行这个过程直到`cur==NULL`。最后返回值为`newhead`。这种方法通过`reverseList_2(struct ListNode* head)`函数实现。

   