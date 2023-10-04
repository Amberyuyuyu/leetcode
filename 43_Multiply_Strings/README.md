### 43.字符串相乘

给定两个以字符串形式表示的非负整数 `num1` 和 `num2`，返回 `num1` 和 `num2` 的乘积，它们的乘积也表示为字符串形式。

**注意：**不能使用任何内置的 BigInteger 库或直接将输入转换为整数。

来源：力扣

https://leetcode.cn/problems/multiply-strings/



思路：

​		将`num1`和`num2`的长度分别表示为`len1`和`len2`。定义字符串`res`，长度为`len1+len2`，将所有字符初始化为'0'。分别定义i和j等于`len2-1`、`len1-1`，用于遍历`num2`、`num1`。定义`temp`变量为`(res[i+j+1]-'0')+(num1[j]-'0')*(num2[i]-'0')`。真实的`res[i+j+1]`应该为`temp%10+'0'`，`res[i+j]`此时应该为`temp/10`(考虑进位)。

​		考虑`res`的真实位数不一定为`len1+len2`，因此将`res`首部为'0'的字符全部去掉并返回`res`。