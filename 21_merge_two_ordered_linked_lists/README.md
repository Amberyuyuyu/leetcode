### 21.合并两个有序链表

将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

来源：力扣

https://leetcode.cn/problems/merge-two-sorted-lists/



思路：

​		这个题类似于按照升序合并两个升序数组。

​		首先对`list1`和`list2`指向的链表进行判断：

​	    `if(list1 == NULL){`
​    		`return list2;`
​		`}`
​		`if(list2 == NULL){`
​    		`return list1;`
​		`}`

​		然后有两种思路：

		1. 定义两个指针：`head`以及`tail`，首先找到头节点，先比较`list1->val`和`list2->val`，将`head`和`tail`均指向它。然后`head`保持不变，不断移动`list1`和`list2`并且判断`val`，不断将较小值所在的节点作为`tail->next`，直到`list1`和`list2`中的一方到达链表末尾。然后判断`list1`和`list2`哪个不为空，再将其放入`tail`末尾。最终返回`head`即可。
		1. 定义两个指针`head`和`tail`，通过`malloc`开辟空间，与第一种大体相似，但`head`代表的是指向头节点的哨兵节点，使用哨兵节点的好处是不需要实现取出两链表的头节点，对它们的`val`进行比较，而是直接在循环中寻找头节点，其余实现与第一种思路相同，最终返回的应该是哨兵节点指向的那个节点的地址：`head->next`。