### 39.组合总和

给你一个 **无重复元素** 的整数数组 `candidates` 和一个目标整数 `target` ，找出 `candidates` 中可以使数字和为目标数 `target` 的 所有 **不同组合** ，并以列表形式返回。你可以按 **任意顺序** 返回这些组合。

`candidates` 中的 **同一个** 数字可以 **无限制重复被选取** 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 `target` 的不同组合数少于 `150` 个。

来源：力扣

https://leetcode.cn/problems/combination-sum/



思路：

​		回溯问题。

​			定义全局变量`path`，用于表示某一个数字和为`target`的组合，`pathTop`表示该数组长度。定义全局变量`ans`，表示最终返回结果，`ansTop`表示`ans`长度，`ansSize`用于表示`ans`中每一个数组的长度。

​		借助快排将数组`candidates`进行升序排序，这样做的目的是在遇到前后相同的数字时，通过跳过操作降低算法的时间复杂度。

​		定义函数`backtracking`，用于完成回溯算法实现。如果遇到`sum==target`时，定义数组`temp`，拷贝此时的`path`，将`temp`存入`ans`中：`ans[ansTop]=temp`， `ansSize[ansTop++]=pathTop`，然后结束本次函数调用。如果`sum>target`，直接结束本次函数调用。	如果`sum<target`时，遇到`sum+candidates[i]`时，直接`break`即可。否则，将`candidates[i]`加入`path`，并执行`sum+=candidates[i]`，由于组合中元素可以重复，因此下一步直接调用`backtracking(candidates,candidatesSize,target,i,sum)`即可。然后将该元素从`path`中移除。