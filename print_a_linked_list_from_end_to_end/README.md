### 剑指 Offer 06. 从尾到头打印链表

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

来源：力扣

https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/



思路：

​	想要将链表元素倒序存入数组中，首先需要知道链表节点总个数。遍历链表，得到`count`。建立数组`arr[count]`，然后通过如下操作对节点数据进行存储：

```
		cur = head;
    while(cur){
    	arr[--count] = cur->val;
        cur = cur->next;
    }
```

