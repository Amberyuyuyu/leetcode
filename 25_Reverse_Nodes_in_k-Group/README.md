### 25.K个一组翻转链表

给你链表的头节点 `head` ，每 `k` 个节点一组进行翻转，请你返回修改后的链表。

`k` 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 `k` 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

来源：力扣

https://leetcode.cn/problems/reverse-nodes-in-k-group/



思路：

​		首先计算出链表的长度，记作`n`。

​		定义哨兵位节点`dummy`，`dummy->next=head`。定义指针`p0`，初始化为指向`dummy`，在遍历时作为暂时的哨兵位节点而存在。用于连接已经排过序的链表和刚刚完成逆置的长度为k的链表段。

​		当`n>=k`时，不断选择`k`个相邻的链表节点进行逆序：

```c
		int tmp = k;
    while(tmp--){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
```

​		首先定义`next=p0->next`，然后将`cur`、`prev`分别作为`p0->next->next`，`p0->next`。最后将临时哨兵位节点置为`next`：`p0=next`。

​	最终返回值为`dummy->next`。