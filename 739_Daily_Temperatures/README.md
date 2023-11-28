### 739.每日温度

给定一个整数数组 `temperatures` ，表示每天的温度，返回一个数组 `answer` ，其中 `answer[i]` 是指对于第 `i` 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 `0` 来代替。

来源：力扣

https://leetcode.cn/problems/daily-temperatures/





思路：

​		定义变量`n`，表示`temperatures`数组的长度。定义`result`数组，用于存放最终结果。

​		定义`ans`数组，长度为`n`，所有元素都初始化为0，用于表示最终结果。

​		定义数组`st`，用于表示一个栈，存放的元素为遍历过的温度对应的下标。

​		定义变量`i`，用于遍历整个数组。当满足`!st.empty()&&temperatures[i]>temperatures[st.top()]`时，设置`result[st.top()]=i-st.top()`，并且弹栈。当不再满足`!st.empty()&&temperatures[i]>temperatures[st.top()]`时，将`i`压入栈中。