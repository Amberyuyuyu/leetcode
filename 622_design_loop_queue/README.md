### 622.设计循环队列

设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

`MyCircularQueue(k)`: 构造器，设置队列长度为 `k` 。
`Front`: 从队首获取元素。如果队列为空，返回 -1 。
`Rear`: 获取队尾元素。如果队列为空，返回 -1 。
`enQueue(value)`: 向循环队列插入一个元素。如果成功插入则返回真。
`deQueue()`: 从循环队列中删除一个元素。如果成功删除则返回真。
`isEmpty()`: 检查循环队列是否为空。
`isFull()`: 检查循环队列是否已满。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/design-circular-queue

思路：

两种方式可以实现循环队列，数组和链表。

1.  数组

   ​		定义两个变量`front`和`tail`，分别代表队尾和队首，由于队列的空间是固定大小，因此，在插入和删除节点时都需要注意队列的情况。如果队列为空时，`front`和`tail`的值相等。但由于队列是循环队列，当队列空间全部占满时，也存在`tail=front`。因此，为了区分这两个边界情况，这里在开辟空间的时候，在队列长度的基础上加1。

   ​		队列采用结构体来存储：

   ```
   		typedef struct {
       		int* a;
      			int front;
      			int tail;
       		int k;
   		} MyCircularQueue;
   ```

   ​		判断循环队列是否为空，就只需要判断`obj->front == obj->tail`即可。而判断循环队列是否已满，需要判断的是`obj->front == (obj->tail+1)%(obj->k+1)`。

   ​		循环队列插入元素时，首先判断队列是否已满，如果已满的话，就返回false，否则，执行以下操作：

   ```
   		obj->a[obj->tail] = value;
       obj->tail++;
       obj->tail%=(obj->k+1);
   ```

   由于是循环队列，因此在确定tail的取值时，计算方式为`obj->tail %= (obj->k+1)`。

   ​		循环队列删除元素时，首先需要判断队列是否为空，为空就直接返回false，否则，执行以下操作：

   ```
   		++obj->front;
      	obj->front %= (obj->k+1);
   ```

   ​		获取队列首元素，如果队列为空，直接返回-1，否则，返回`obj->a[obj->front]`。

   ​		获取队尾元素时，如果队列为空，返回-1，队列不为空时，存在两种情况：`tail`是否为0。`tail`为0时，应该返回`obj[obj->k]`，否则，返回`obj->a[obj->tail-1]`。

2. 链表

​				如果将循环队列通过链表的方式进行实现，则需要作出如下定义：

```
			typedef struct CQNode {
					int data;
					struct CQNode* next;
			}CQNode;
			typedef struct {
					CQNode* front;
					CQNode* tail;
					int size;
					int k;
			} MyCircularQueue;
```

​			用`front`指针来表示队列的头节点，`tail`指针代表队列的尾节点。`size`代表队列中存储元素个数。

​			判断队列是否为空，只需判断`size`是否为0。判断队列是否已满，需要判断`size`是否等于`k`。

​			在队列中插入元素时，首先判断队列是否已满，队列已满的话，直接返回`false`即可。如果队列未满，则对`obj->front`和`obj->tail`进行判断，如果为初始化时赋值的`NULL`，说明队列中还没有元素，那么就将`tail`和`front`都指向新定义的节点`newnode`,否则，执行以下操作：

			obj->tail->next = newnode;
			obj->tail = newnode;

​			在改变指针指向以后，还需要对`size`进行+1操作。

​			在队列中删除元素时，首先判读啊队列是否为空，如果为空，直接返回`false`，否则，将`front`指向队列的第二个节点，`size--`即可：

			CQNode* head = obj->front;
			obj->front = head->next;
			free(head);
			obj->size--;
​			获取队列首元素，如果队列为空，返回-1，否则，返回`obj->front->data`。获取队列队尾元素，如果队列为空，返回-1，否则，返回`obj->tail->data`。