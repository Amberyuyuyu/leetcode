### 1385.两个数组间的距离值

给你两个整数数组 `arr1` ， `arr2` 和一个整数 `d` ，请你返回两个数组之间的 **距离值** 。

「**距离值**」 定义为符合此距离要求的元素数目：对于元素 `arr1[i]` ，不存在任何元素 `arr2[j]` 满足 `|arr1[i]-arr2[j]| <= d` 。

来源：力扣

https://leetcode.cn/problems/find-the-distance-value-between-two-arrays/



思路：		

​		定义`num = arr1.size()`，采用暴力解法，如果`abs(arr1[i]-arr2[j])<=d`，就执行`num--`，然后`break`，跳出内层循环。最后返回`num`即可。