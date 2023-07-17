### 415.字符串相加

给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/add-strings



思路：

​	首先这两个字符串的长度，分别记作`len1`、`len2`；

​	定义变量`i`和变量`j`，分别初始化为`len1-1`、`len2-1`；

​	定义数组`ret`，长度为`len1+len2+1`；

​	定义变量`count`，用于存放`ret`数组元素个数，初始化为0;

​	定义变量`sum`，初始化为0，用于存放由`num1`和`num2`转化出的数字的和；

​	首先从两字符串的末尾开始，同步遍历`num1`和`num2`，直到有一个字符串遍历结束为止：

```c
	while (i >= 0 && j >= 0) {
    int x = num1[i] - '0';
    int y = num2[j] - '0';
    int sum = x + y + flag;
    ret[count++] = '0' + sum%10;
    flag = sum / 10;
    i--;
    j--;
}
```

​	`flag`初始化为0，表示需要进位的数字为多少，`flag=0`表示不需要进位。

​	第一次遍历结束后，判断i是否大于等于0，如果是的话，执行如下操作：

```c
	while (i >= 0) {
        char sum = (num1[i--] - '0') + flag;
        ret[count++] = '0' + sum % 10;
        flag = sum / 10;
    }
```

​	同样地，如果`num2`长度大于`num1`，则经过一次遍历后，`j`仍旧大于等于0，就需要对`num2`执行如下操作：

```c
while (j >= 0) {
        char sum = (num2[j--] - '0') + flag;
        ret[count++] = '0' + sum % 10;
        flag = sum / 10;
}
```

​	最后判断`flag`的值，如果`flag`不为0，就需要进位：

```c
	ret[count++] = '0'+flag;
```

​	现在的`ret`为逆序，还应该将所有元素倒置，并在末尾加'\0'，才可以得到最终结果：

```c
	for(int i=0; i<count/2; i++){
    char tmp = ret[i];
    ret[i] = ret[count-i-1];
    ret[count-i-1] = tmp;
	}
	ret[count] = 0;
```