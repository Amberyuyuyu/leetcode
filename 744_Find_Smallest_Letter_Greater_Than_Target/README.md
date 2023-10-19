### 744.寻找比目标字母大的最小字母

给你一个字符数组 `letters`，该数组按**非递减顺序**排序，以及一个字符 `target`。`letters` 里**至少有两个不同**的字符。

返回 `letters` 中大于 `target` 的最小的字符。如果不存在这样的字符，则返回 `letters` 的第一个字符。

来源：力扣

https://leetcode.cn/problems/find-smallest-letter-greater-than-target/



思路：

​		定义`left=0`，`right=letters.size()-1`。当满足`left<right`时，定义`mid=left+(right-left)/2`，如果`target>=letters[mid]`，目标值应该在`mid`到结尾的部分中出现，此时`left=mid+1`，否则，`right=mid`。

​	   如果最终结果为`letters[left]>target`，返回`letters[left]`，否则，返回`letters[0]`。		