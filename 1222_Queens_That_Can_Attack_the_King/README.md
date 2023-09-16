### 1222.可以攻击国王的皇后

在一个 **8x8** 的棋盘上，放置着若干「黑皇后」和一个「白国王」。

给定一个由整数坐标组成的数组 `queens` ，表示黑皇后的位置；以及一对坐标 `king` ，表示白国王的位置，返回所有可以攻击国王的皇后的坐标(任意顺序)。

来源：力扣

https://leetcode.cn/problems/queens-that-can-attack-the-king/



思路：

​		宏定义`N`为8，定义全局变量`dx[N]={-1,-1,-1,0,0,1,1,1}`和`dy[N]={-1,0,1,-1,1,-1,0,1}`，`dx`和`dy`中按照下标顺序，可以构成八个坐标，分别代表某个坐标周围的八个移动方向。

​		定义二级指针`ans`，用于存放最终结果。定义`map[8][8]`,遍历整个`queens`，将`map`中对应下标元素置为1。分别定义`x=king[0]`，`y=king[1]`。

​		遍历`dx`和`dy`数组，定义临时变量`temx = x +dx[i]`，`tempy = y+dy[i]`。当满足`tempx>=0&&tempx<8&&tempy>=0&&tempy<8&&map[tempx][tempy]!=1`时，执行`tempx += dx[i]`，`tempy += dy[i]`。如果不满足上述条件时`tempx<0||tempx>=8||tempy<0||tempy>=8`，说明此方向上没有出现满足条件的皇后，跳出循环，判断下一个方向(更换`dx`和`dy`)。如果此时`map[tempx][tempy]==1`，就将此时的`tempx`和`tempy`存入`ans`中。

​		最终返回结果为`ans`。

​		