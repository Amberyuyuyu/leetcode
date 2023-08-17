### 128.最长连续序列

给定一个未排序的整数数组 `nums` ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 `O(n)` 的算法解决此问题。

来源：力扣

https://leetcode.cn/problems/longest-consecutive-sequence/



思路：

​		定义一个集合`hash_set`，存放`nums`，目的是去重。

​		定义变量`max_len`，初始化为0。

​		遍历整个`nums数`组，如果`num-1`不在定义的集合`hash_set`中，就执行如下操作：

```python
		cur_num = num
    cur_streak = 1
    while cur_num+1 in hash_set:
    	cur_num += 1
    	cur_streak += 1
    max_len = max(max_len,cur_streak)
```

​		如果`num-1`不在`hash_set`中，就将`num`作为序列首个元素，从`num`开始计算长度`cur_streak`，每次都将`max_len`与`cur_streak`进行比较，得到最大的序列长度。