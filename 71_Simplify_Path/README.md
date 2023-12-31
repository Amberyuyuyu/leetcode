### 71.简化路径

给你一个字符串 `path` ，表示指向某一文件或目录的 Unix 风格 **绝对路径** （以 `'/'` 开头），请你将其转化为更加简洁的规范路径。

在 Unix 风格的文件系统中，一个点（`.`）表示当前目录本身；此外，两个点 （`..`） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，`'//'`）都被视为单个斜杠 `'/'` 。 对于此问题，任何其他格式的点（例如，`'...'`）均被视为文件/目录名称。

å请注意，返回的 **规范路径** 必须遵循下述格式：

- 始终以斜杠 `'/'` 开头。
- 两个目录名之间必须只有一个斜杠 `'/'` 。
- 最后一个目录名（如果存在）**不能** 以 `'/'` 结尾。
- 此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 `'.'` 或 `'..'`）。

返回简化后得到的 **规范路径** 。

来源：力扣

https://leetcode.cn/problems/simplify-path/description/

思路：

​	首先通过`strlen`函数得到`path`的长度`n`，建立`stack`数组，长度为`n`，用于存放`/`分隔符之间的字符串。借助`strtok`函数来对`path`进行分割：

			for(char* s=strtok(path,"/");s;s=strtok(NULL,"/")){
	    	if(strcmp(s,".")==0){
	
	    	}else if(strcmp(s,"..")==0){
	        	size = fmax(0,size-1);
	    	}else{
	        	stack[size++]=s;
	    	}
			}

​		如果`size`为0，就直接返回"/"。

​		定义长度为`n+1`的字符串`res`，用于存放简化结果：

			char* res = calloc(n+1,sizeof(char));
			for(int i=0; i<size; i++){
	    	strcat(res,"/");
	    	strcat(res,stack[i]);
		}