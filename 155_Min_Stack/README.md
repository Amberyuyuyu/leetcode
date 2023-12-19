### 155.最小栈

设计一个支持 `push` ，`pop` ，`top` 操作，并能在常数时间内检索到最小元素的栈。

实现 `MinStack` 类:

- `MinStack()` 初始化堆栈对象。
- `void push(int val)` 将元素val推入堆栈。
- `void pop()` 删除堆栈顶部的元素。
- `int top()` 获取堆栈顶部的元素。
- `int getMin()` 获取堆栈中的最小元素

来源：力扣

https://leetcode.cn/problems/min-stack/



思路：

​		根据题意，在弹栈压栈过程中栈中最小元素都有可能发生变化，因此需要再建一个栈专门用于存放对应于当前最小栈维度对应的最小的元素。最小栈和最小元素栈分别定义为`vals`和`minvals`。

​		在压栈操作中，执行`vals.emplace(val)`，判断最小元素栈是否为空，如果为空，直接压栈：`minvals.emplace(val)`，否则比较最小元素栈栈顶元素和要压栈的元素，将较小值压入最小元素栈：`minvals.emplace(min(minvals.top(),val))`。

​		弹栈操作，需要两个栈都执行弹栈操作。

​		在获取栈中最小元素时，只需要调用`minvals.top()`函数即可。

​		