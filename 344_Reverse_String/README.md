### 344.反转字符串

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reverse-string



思路：

​		定义左右指针`left`和`right`，分别初始化为0和`sSize-1`。

​		当满足`left<right`时，交换`s[left]`和`s[right]`，然后将`left++`，`right--`。

​		最后返回`s`即可。

​		

