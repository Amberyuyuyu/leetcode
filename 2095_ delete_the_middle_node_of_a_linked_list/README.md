### 2095.删除链表的中间节点

给你一个链表的头节点 head 。删除 链表的 中间节点 ，并返回修改后的链表的头节点 head 。

长度为 n 链表的中间节点是从头数起第 ⌊n / 2⌋ 个节点（下标从 0 开始），其中 ⌊x⌋ 表示小于或等于 x 的最大整数。

对于 n = 1、2、3、4 和 5 的情况，中间节点的下标分别是 0、1、1、2 和 2 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/delete-the-middle-node-of-a-linked-list



思路：

​		需要找到中间节点，同时标记它的前一节点和后一节点，以便于删除中间节点。

​		定义新指针`slow`和`fast`，初始化为`head`。

​		通过`slow`和`fast`遍历链表，`slow`指针每次都走一步，`fast`指针每次都走两步。

​		如果链表共有偶数个节点，遍历停止条件为`fast==NULL`。

​		如果链表有奇数个节点，遍历停止条件为`fast.next==NULL`。

​		遍历结束时记录`prev`为`slow`的前一节点，遍历停止时，`slow`指向的就是中间节点，`prev`为它的前一节点。定义`next = slow->next`。执行`prev->next=next`。最后返回head即可。

​		