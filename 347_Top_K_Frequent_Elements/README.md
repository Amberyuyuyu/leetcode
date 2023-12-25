### 347.前k个高频元素

给你一个整数数组 `nums` 和一个整数 `k` ，请你返回其中出现频率前 `k` 高的元素。你可以按 **任意顺序** 返回答案。

来源：力扣

https://leetcode.cn/problems/top-k-frequent-elements/



思路：

​		定义数组`ret`，用于存放最终结果。定义map类型的变量`fir`，用于存放数字以及对应的出现次数。

​		定义multimap类型的变量`sec`，用于存放出现次数以及对应的数字，采用升序排列。

​		定义`it=sec.begin()`，当满足`it!=sec.end()`时，如果k==0，说明已经找到前`k`个高频数字。否则的话，执行：

```c
			ret.push_back(it->second);
      ++it;
      --k;
```

​		