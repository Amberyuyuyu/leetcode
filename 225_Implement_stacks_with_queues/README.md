### 225.用队列实现栈

请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（`push`、`top`、`pop` 和 `empty`）。

实现 `MyStack` 类：

`void push(int x)` 将元素 x 压入栈顶。
`int pop()` 移除并返回栈顶元素。
`int top()` 返回栈顶元素。
`boolean empty()` 如果栈是空的，返回 `true` ；否则，返回 `false` 。


注意：

你只能使用队列的基本操作 —— 也就是 `push to back`、`peek/pop from front`、`size` 和 `is empty` 这些操作。
你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/implement-stack-using-queues

思路：

​	队列的特点是先进先出，栈的特点是先进后出。

​	入栈时，需要借助一个队列即可，判断哪个队列不为空，就将数据存放进哪个队列，如果都为空，就任意存放。

​		弹栈时，根据栈和队列的特点，这里需要借助`QueuePop`和`QueuePush`函数，将队列中除最后一个元素外的其他元素全部通过转移到空队列中，然后返回最后一个元素即可，同时通过`QueuePop`将最后一个元素也弹栈。

​		返回栈顶元素，首先需要借助`QueueEmpty`函数判断哪个队列不为空，然后通过`QueueBack`返回这个队列队尾元素即可。

​		判断栈是否为空，需要借助`QueueEmpty`判断两个队列是否为空，如果两个队列都为空就返回`true`，否则返回`false`。