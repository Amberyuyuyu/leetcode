### 833.字符串中的查找与替换

你会得到一个字符串 `s` (索引从 0 开始)，你必须对它执行 `k` 个替换操作。替换操作以三个长度均为 `k` 的并行数组给出：`indices`, `sources`, `targets`。

要完成第 `i` 个替换操作:

1. 检查 **子字符串** `sources[i]` 是否出现在 **原字符串** `s` 的索引 `indices[i]` 处。
2. 如果没有出现， **什么也不做** 。
3. 如果出现，则用 `targets[i]` **替换** 该子字符串。

例如，如果 `s = "abcd"` ， `indices[i] = 0` , `sources[i] = "ab"`， `targets[i] = "eee"` ，那么替换的结果将是 `"eeecd"` 。

所有替换操作必须 **同时** 发生，这意味着替换操作不应该影响彼此的索引。测试用例保证元素间**不会重叠** 。

- 例如，一个 `s = "abc"` ， `indices = [0,1]` ， `sources = ["ab"，"bc"]` 的测试用例将不会生成，因为 `"ab"` 和 `"bc"` 替换重叠。

*在对 `s` 执行所有替换操作后返回 **结果字符串** 。*

**子字符串** 是字符串中连续的字符序列。



来源：力扣

https://leetcode.cn/problems/find-and-replace-in-string/



思路：

​		`indeces`数组元素可能为乱序，因此需要将`indices`、`sources`、`targets`中元素按顺序存入结构体`map`中。定义结构体数组`arr`，用于存放`indicesSize`个结构体。定义`cmp`函数，借助快速排序，用于将结构体按照`index`进行排序。

​		定义字符串`res`，赋初值为`s`。

​		借助变量`i`遍历整个字符串`res`，遇到`res[arr[i].index]`与`arr[i].source`相等时，执行如下操作：

```
			memset(buf,0,sizeof(char));
      strcpy(buf,arr[i].target);
      strcat(buf,&res[arr[i].index+strlen(arr[i].source)]);
      memset(&res[arr[i].index],0,sizeof(char));
      strcat(&res[arr[i].index],buf);
```

​	最终返回值就是`res`。