### 692.前K个高频单词

给定一个单词列表 `words` 和一个整数 `k` ，返回前 `k` 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率， **按字典顺序** 排序。

来源：力扣

https://leetcode.cn/problems/top-k-frequent-words/



思路：

​		定义一个map类型的变量`countMap`，用于存放单词和他们对应的出现次数。遍历一次`words`数组，完成对单词出现次数的统计。

​		定义一个multimap类型的变量`sortMap`，用于存放出现次数以及对应的单词，并按照降序排列。遍历`countMap`，完成`sortMap`的填写。

​		定义`it=sortMap.begin()`，当满足`it!=sortMap.end()`，如果`k==0`，直接`break`，说明已经找到前`k`个高频单词。否则，执行：

```c
	v.push_back(it->second);
  ++it;
 	--k;
```

​		