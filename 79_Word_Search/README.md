### 79.单词搜索

给定一个 `m x n` 二维字符网格 `board` 和一个字符串单词 `word` 。如果 `word` 存在于网格中，返回 `true` ；否则，返回 `false` 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

来源：力扣

https://leetcode.cn/problems/word-search/



思路：

​		回溯问题。

​		定义二级指针`visited`，用于表示位置`(i, j)`上的元素是否被访问过。将`visited`矩阵初始化为0。定义全局二维矩阵`directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}`。

​		定义变量`len=strlen(word)`，利用嵌套循环遍历数组`board`，借助函数`check`判断从`(i, j)`出发，能否搜索到单词`word[k...]`（字符串`word`从`k`出发的子串），能搜索到就直接返回`true`，结束遍历。

​		函数`check`，完成了回溯算法。如果此时`board[i][j]!=s[k]`，直接返回`false`结束，进行别的`i`和`j`的判断。如果此时`k==sSize-1`，直接返回`true`，说明找到了`word`。否则的话，设置`visited[i][j]=1`，根据题目中的思路，遍历整个`directions`，得到新的`x`和`y`：`int newi = i + directions[m][0]`,`int newj = j + directions[m][1]`;如果新坐标仍旧在`board`横纵坐标范围内，并且满足`visited[newi][newj]!=1`，就判断此时新坐标出发能否找到`word[k+1...]`：`bool ret = check(board,boardSize,boardColSize,visited,newi,newj,s,sSize,k+1)`，如果`ret==true`，直接返回`true`。

​		