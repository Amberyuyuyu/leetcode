### 2651.计算列车到站时间

给你一个正整数 `arrivalTime` 表示列车正点到站的时间（单位：小时），另给你一个正整数 `delayedTime` 表示列车延误的小时数。

返回列车实际到站的时间。

注意，该问题中的时间采用 24 小时制。

来源：力扣

https://leetcode.cn/problems/calculate-delayed-arrival-time/



思路：

​		`arrivalTime+delayedTime`应该为实际到达时间，但由于两者相加后可能会跨天，因此需要将两者的和取余数，才得到最终结果。