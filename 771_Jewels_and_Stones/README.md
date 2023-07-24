### 771.宝石与石头

 给你一个字符串 `jewels` 代表石头中宝石的类型，另有一个字符串 `stones` 代表你拥有的石头。 `stones` 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。

字母区分大小写，因此 "a" 和 "A" 是不同类型的石头。



来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/jewels-and-stones



思路

​	'A'的ASCII码：65

​	'z'的ASCII码：122

​	因此直接建立一个长度为58的数组`arr`，将所有元素都初始化为0，按照顺序存放`jewels`中出现过的字母。如果在`jewels`中出现，就将`arr`数组对应位置上的值改为1。

​	遍历`stones`数组，如果`arr[*stones-65]`为1，就执行`count++`操作。

​	最终返回`count`即可。