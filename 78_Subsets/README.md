78.子集

给你一个整数数组 `nums` ，数组中的元素 **互不相同** 。返回该数组所有可能的子集（幂集）。

解集 **不能** 包含重复的子集。你可以按 **任意顺序** 返回解集。



来源：力扣

https://leetcode.cn/problems/subsets/



思路：

​		回溯问题。

​		定义数组`path`和`result`，分别用于存放某个可能的子集以及最终返回结果。

​		定义函数`backtracking`，每次调用时，都先执行`result.append(path[:])`，从startIndex开始，定义变量i进行遍历，每次都执行如下代码：

		path.append(nums[i])
	  self.backtracking(nums,i+1,path,result)
	  path.pop()