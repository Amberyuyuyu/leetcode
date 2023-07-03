### 445.两数相加II

给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/add-two-numbers-ii



思路：

​		将两个链表所有节点数字链接在一起，求两数之和，并按照将每一位数字按照顺序放入新链表。

​		首先判断是否存在链表为空，若一个链表为空，则直接返回另一个即可。

​		由于链表中数据映射到数字时，是高位在前，低位在后，因此首先借助`reverseList`函数将两个链表进行翻转。翻转后的`l1`通过`head1`指针表示，`l2`通过`head2`表示。

​		将两链表长度求出，分别记作`len1`和`len2`。

​		将较长的链表记为`longList`，较短的记为`shortList`。

​		定义一个整型变量`flag`，用于标记是否需要进位，初始化为0（表示不进位）。

​		在相加过程中，一定是短的先为空。因此第一次遍历时截止条件为`shortList==NULL`：

			while(shortList){
	    	if(flag == 1){
	        	longList->val += 1;
	        	flag = 0;
	    	}
	    	longList->val = longList->val+shortList->val;
	    	if(longList->val >= 10){
	        	longList->val = longList->val%10;
	        	flag = 1;
	    	}
	    	prev = longList;
	    	longList = longList->next;
	    	shortList = shortList->next;
		}

​		在遍历时始终记录`longList`的前一节点`prev`。

​		如果在本次遍历结束后，`longList==NULL`，说明两链表同样长。此时如果`flag=1`，说明最后一次相加时需要进位，那么就`malloc`一个新节点的空间，将其链接在`prev`后：

		if(longList==NULL && flag){
	    	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	    	newnode->val = 1;
	    	newnode->next = NULL;
	    	prev->next = newnode;
	    	head = reverseList(newhead);
	    	return head;
		}

​		如果第一次遍历后`longList !=NULL`，说明长链表还有元素。此时就需要继续遍历长链表，仍需要注意进位情况：

		while(longList){
	    if(flag){
	        longList->val += 1;
	        flag = 0;
	    }
	    if(longList->val >= 10){
	        longList->val %= 10;
	        flag = 1;
	    }
	    prev = longList;
	    longList = longList->next;
	}

​		此时，两个链表数字都遍历完毕，但仍旧存在特殊情况`flag=1`，此时需要再次创建新节点链接至`prev`之后，然后翻转链表，返回最终结果。