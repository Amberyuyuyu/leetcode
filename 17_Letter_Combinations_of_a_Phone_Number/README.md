### 17.电话号码的组合

给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。答案可以按 **任意顺序** 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

![image](https://github.com/Amberyuyuyu/leetcode/blob/master/17_Letter_Combinations_of_a_Phone_Number/num.png)

来源：力扣

https://leetcode.cn/problems/letter-combinations-of-a-phone-number/



思路：

​		回溯的思路来解题。

​		定义一个数组`MAPPING=["", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]`，目的是将这些字符串与电话号码的数字键对应起来。

​		定义`n=len(digits)`，如果`n`为0，直接返回一个空数组即可。定义长度为`n`的空数组`path`，用于存放可能的组合，定义数组`ans`，用于存放最终返回结果。

​	定义函数`dfs`，每次传入`path`中元素个数。如果此时`i==n`，就将`path`中所有元素合并为一个字符串，传入`ans`。如果`i<n`，就遍历`dights[i]`中所有字符，存入`path[i]`，并调用`dfs(i+1)`以寻找下一个元素。

​	在主函数中调用`dfs(0)`，最终返回`ans`即可。
