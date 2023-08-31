### 823.带因子的二叉树

给出一个含有不重复整数元素的数组 `arr` ，每个整数 `arr[i]` 均大于 1。

用这些整数来构建二叉树，每个整数可以使用任意次数。其中：每个非叶结点的值应等于它的两个子结点的值的乘积。

满足条件的二叉树一共有多少个？答案可能很大，返回 **对** `109 + 7` **取余** 的结果。

来源：力扣

https://leetcode.cn/problems/binary-trees-with-factors/



思路：

​		动态规划+双指针

​		首先定义`cmp`函数，通过快排将`arr`数组中元素升序排列。

​		定义`long long int`类型变量`ret`，初始化为0，定义`mod`，赋值为1e9+7。

​		定义`dp`数组，用于存放动态规划结果。`dp[i]`表示当根节点为`arr[i]`时，满足条件的二叉树个数。

​		定义变量`i`，用于遍历整个`arr`。

​		将所有`dp[i]`初始化为1，表示单独一个`arr[i]`作为一棵二叉树。

​		定义变量`left`和`right`，分别表示`arr[i]`对应的子节点。`left`初始化为0，`right`初始化为`i-1`。当满足`left<=right`时，如果`(long long)arr[left]*arr[right]>arr[i]`，执行`right--`。当满足`(long long)arr[left]*arr[right]==arr[i]`时，如果`left==right`，这时`dp[i]`的值为`(dp[i]+dp[right]*dp[left])%mod`，否则，`dp[i]=(dp[i]+dp[right]*dp[left]*2)%mod`。因为如果`left != right`时，交换`left`和`right`两节点的位置，就会得到新的二叉树。

​		`ret = (ret+dp[i])%mod`。

​		最终返回结果就是`ret`。		

​		

​		