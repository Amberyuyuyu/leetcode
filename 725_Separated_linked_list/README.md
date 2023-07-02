### 725.分隔链表

给你一个头结点为 `head` 的单链表和一个整数 `k` ，请你设计一个算法将链表分隔为 `k` 个连续的部分。

每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过 1 。这可能会导致有些部分为 `null` 。

这 k 个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。

返回一个由上述 `k` 部分组成的数组。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/split-linked-list-in-parts

思路：

​		首先遍历链表，获得链表长度`len`。

```
		split=len/k;
		remain=len%k;
```

​		如果`split`为0，说明链表节点个数小于`k`，因此每个节点都会被分隔开来。

​		如果`split`不为0，那么前`remain`个分隔链表长度都应该为`split+1`：

			while(k--){
	        res[i++] = cur;
	        for(int j=0;j<split+(remain>0?0:-1);j++){
	            cur = cur->next;
	        }
	        remain--;
	        next = cur->next;
	        cur->next = NULL;
	        cur = next;
	    }

​		