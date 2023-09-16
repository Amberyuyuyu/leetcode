### 48.旋转图像

给定一个 *n* × *n* 的二维矩阵 `matrix` 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在**[ 原地](https://baike.baidu.com/item/原地算法)** 旋转图像，这意味着你需要直接修改输入的二维矩阵。**请不要** 使用另一个矩阵来旋转图像。

来源：力扣

https://leetcode.cn/problems/rotate-image/



思路：

​		根据旋转后图像与旋转前的关系，我们可以先将图像矩阵进行转置，再镜像就可以得到旋转后的结果。

​		转置其实就是将矩阵元素，主对角线对称位置元素进行交换即可。操作如下：

```c
	for(int i=0; i<m; i++){
    for(int j=i; j<n; j++){
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }
	}
```

​	镜像操作就是以矩阵最中间一列元素为轴，将两边对应的元素进行交换：

```c
	int left = 0;
	int right = n-1;
	while(left < right){
    for(int i=0; i<m; i++){
        int temp = matrix[i][left];
        matrix[i][left] = matrix[i][right];
        matrix[i][right] = temp;
    }
    left++;
    right--;
	}
```