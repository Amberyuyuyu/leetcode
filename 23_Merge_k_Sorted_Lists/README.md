### 23.合并K个升序链表

给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。



思路：

​		参考合并两个有序列表的思路，合并`k`个有序链表，采用分治法的思路，将`k`个链表配对，并将同一对中的链表合并，第一轮合并后，`k`个链表变为`k/2`个链表，然后变为`k/4`个链表....最终合并为一个链表：

	if(l > r){
	    return NULL;
	}
	if(l == r){
	    return lists[l];
	}
	int mid = l + (r-l)/2;
	struct ListNode* l1 = TwoList(lists,l,mid);
	struct ListNode* l2 = TwoList(lists,mid+1,r);
	return mergeTwoList(l1,l2);