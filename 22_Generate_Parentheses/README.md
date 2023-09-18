### 22.括号生成

数字 `n` 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 **有效的** 括号组合。

来源：力扣

https://leetcode.cn/problems/generate-parentheses/



思路：

​		回溯问题。

​		定义函数`generate`，用于实现回溯算法。str代表当前生成的字符串，index代表str的长度，left表示str中左半括号的个数，right代表str中右半括号的个数。如果`index==2*n`，说明所有的括号生成完毕，将此时的`str`加入到`ret`中。如果此时的`left<n`，可以在当前`str`中追加`'('`，然后执行下一步操作：`generate(left+1,right,n,index+1,returnSize)`。如果此时的`right<left`，可以在`str`上追加`')'`，然后执行： `generate(left,right+1,n,index+1,returnSize)`。

​		