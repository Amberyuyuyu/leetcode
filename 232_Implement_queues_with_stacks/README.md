### 232.用栈实现队列

请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（`push`、`pop`、`peek`、`empty`）：

实现 `MyQueue` 类：

`void push(int x)` 将元素 x 推到队列的末尾
`int pop()` 从队列的开头移除并返回元素
`int peek()` 返回队列开头的元素
`boolean empty()` 如果队列为空，返回 `true` ；否则，返回 `false`
说明：

你 只能 使用标准的栈操作 —— 也就是只有 `push to top`, `peek/pop from top`, `size`, 和 `is empty` 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/implement-queue-using-stacks

思路：

​		栈的特点是先进后出，队列的特点是先进先出。

​		要通过栈实现队列，需要定义两个栈，`pushSt`用来入对，`popSt`用来出队。

​		入队时只需要将元素`x`通过`StackPush`函数入栈`pushSt`即可

​		出队时，需要判断`popSt`是否为空，如果不为空，直接借助`StackPop`出栈即可，如果`popSt`为空，则需要在`pushSt`不为空时，将`pushSt`中的元素都放入`popSt`中，再执行出栈操作。

​		查找队列开头元素时，大体思路与出队时相同。

​		判断队列是否为空，需要借助`StackEmpty`函数判断`pushSt`和`popSt`,它们同时为空时，返回`true`,否则返回`false`。