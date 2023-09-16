### 54.螺旋矩阵

给你一个 `m` 行 `n` 列的矩阵 `matrix` ，请按照 **顺时针螺旋顺序** ，返回矩阵中的所有元素。

来源：力扣

https://leetcode.cn/problems/spiral-matrix/



思路：

​		如果`*matrixColSize==0`或`matrixSize==0`，直接返回`NULL`。

​		定义`m`和`n`分别为矩阵的行和列的维度。定义指针`ret`，用于指向最终返回的结果。圈数计算方式：`squre=fmin(m/2, n/2)`。定义变量`startx`和`starty`，用于标记每一圈开始位置的`x`和`y`坐标。定义变量`offset`，初始化为1，用于遍历整个数组，它标记的是具体圈数，取值范围是`[0, squre]`。每一圈中路径都是顺时针顺序。因此可以分为四步：

```c
		for(int j=starty; j<n-offset; j++){
        ret[(*returnSize)++] = matrix[startx][j];
    }
    for(int i=startx; i<m-offset; i++){
        ret[(*returnSize)++] = matrix[i][n-offset];
    }
    for(int j=n-offset; j>starty; j--){
        ret[(*returnSize)++] = matrix[m-offset][j]; 
    }
    for(int i=m-offset; i>startx; i--){
        ret[(*returnSize)++] = matrix[i][starty];
    }
```

​	在走完一圈时，`startx`和`starty`此时都增加1。

​	如果`m`和`n`中的较小值为奇数，在走完`squre`圈以后，还会遗留一些元素，需要将他们也加入最终结果：

```c
	if (m<n){
        for(int j=squre; j<n-squre; j++){
            ret[(*returnSize)++] = matrix[squre][j];
        }
   }else{
        for(int i=squre; i<m-squre; i++){
            ret[(*returnSize)++] = matrix[i][squre];
        }
   }
```