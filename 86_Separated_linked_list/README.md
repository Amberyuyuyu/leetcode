### 86.分隔链表

给你一个链表的头节点 `head` 和一个特定值 `x` ，请你对链表进行分隔，使得所有 小于 `x` 的节点都出现在 大于或等于 `x` 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/partition-list

思路：

​		创建两个指针：`smallHead`和`smallTail`，用来存放原链表中所有`val`都小于`x`的节点，`smallHead`为哨兵位指针，指向第一个节点；

​		创建两个指针：`bigHead`和`bigTail`，用来存放原链表中所有`val`都大于等于`x`的节点，`bigHead`为哨兵位指针，指向第一个节点；

​		创建一个指针`cur`，初始化为`head`，通过`cur`指针遍历整个链表，将复合条件的值分别放入上述两个链表中；

​		遍历完整个链表时，存在两种情况：

   - 最后一个节点的`val`大于`x`，此时只要`smallTail->next = bigHead->next`即可；

   - 倒数第二个节点的`val`大于`x`，而最后一个节点的`val`小于`x`，此时则需要`bigTail->next = NULL`，再执行`smallTail->next = bigHead->next`。

     最后函数的返回值应该为`smallHead->next`。