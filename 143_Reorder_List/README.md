### 143.重排链表

给定一个单链表 `L` 的头节点 `head` ，单链表 L 表示为：

​	`L0 → L1 → … → Ln - 1 → Ln`
请将其重新排列后变为：

​	`L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …`
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reorder-list



思路：

​		建立`struct ListNode*`类型的数组`arr`：`struct ListNode* arr[50000]`;

​		初始化指针`cur=head`，通过`cur`遍历链表，将所有节点存入数组`arr`中，并得到链表长度`i`。

​		定义整型变量`j`，初始化为1，通过`for`循环重组链表，每次`cur->next`对象有所改变：

			for(int j=1; j<=i/2; j++){
	    	cur ->next = arr[i-j];
	    	cur = cur->next;
	    	cur->next = arr[j];
	    	cur = cur->next;
			}

​	最后还需要将`cur->next`置为`NULL`。