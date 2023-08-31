### 2.两数相加

给你两个 **非空** 的链表，表示两个非负的整数。它们每位数字都是按照 **逆序** 的方式存储的，并且每个节点只能存储 **一位** 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

来源：力扣

https://leetcode.cn/problems/add-two-numbers/



思路：

​		定义`cur1`和`cur2`两个指针，分别初始化为`l1`和`l2`。

​		定义变量`flag`，用于标记需要进位的值，初始化为0。

​		定义指针`head`和`tail`，初始化为`NULL`。

​		当`cur1`和`cur2`有一方不为`NULL`时，定义`num1`和`num2`，如果`cur1->val`和`cur2->val`有意义时，直接赋值给`num1`和`num2`，否则赋值为0。定义变量`va`l：`val=num1+num2+flag`。如果此时`head`为`NULL`，就给`head`以及`tail`赋值：

```c
     head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
     tail->val = val%10;
     tail->next = NULL;
```

​		否则就定义一个节点`tail->next`，赋值并将`tail`后移：

```c
		  tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		  tail->next->val = val%10;
		  tail = tail->next;
		  tail->next = NULL;
```

​		`flag`置为`val/10`。

​		如果此时`cur1不`为空，就将`cur1`后移一个节点，同理，对`cur2`进行这个操作。

​		如果遍历结束后，`flag`不为0，就开辟新节点，存放`flag`的值。

​		最后，返回`head`即可。