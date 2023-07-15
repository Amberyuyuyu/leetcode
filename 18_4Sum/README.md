### 18.四数之和

给你一个由 `n` 个整数组成的数组 `nums` ，和一个目标值 `target` 。请你找出并返回满足下述全部条件且不重复的四元组 `[nums[a], nums[b], nums[c], nums[d]]` （若两个四元组元素一一对应，则认为两个四元组重复）：

`0 <= a, b, c, d < n`
`a`、`b`、`c` 和 `d` 互不相同
`nums[a] + nums[b] + nums[c] + nums[d] == target`
你可以按 任意顺序 返回答案 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/4sum



思路：

​	与三数之和的思路相似，只不过需要定义`k`、`i`、`left`、`right`四个变量用于表示`a`、`b`、`c`、`d`四个数。

​	首先将数组`nuns`进行非降序排序。

​	`k`的取值范围：`[0,numsSize)`，i的取值范围：`[k+1,numsSize)`

​	第一次剪枝操作：

		if(nums[k]>=0 && nums[k] > target){
	        break;
	  }

​		第一次去重：

		 if(k>0 && nums[k]==nums[k-1]){
		 		continue;
	   }

​		第二次剪枝：

		if(nums[i]+nums[k]>=0 && nums[i]+nums[k]>target){
	  		break;
	  }

​		第二次去重：

		 if(i>k+1 && nums[i]==nums[i-1]){
	   		continue;
	   }

​		第三次去重：

				int* ans = (int*)malloc(sizeof(int)*4);
	      ans[0] = nums[k];
	      ans[1] = nums[i];
	      ans[2] = nums[left];
	      ans[3] = nums[right];
	      result[count++] = ans;
	      while(left<right && nums[left] == nums[left+1]){
	           left++;
	      }
	      while(left<right && nums[right] == nums[right-1]){
	           right--;
	      }