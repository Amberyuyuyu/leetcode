### 289.生命游戏

根据 [百度百科](https://baike.baidu.com/item/生命游戏/2926434?fr=aladdin) ， **生命游戏** ，简称为 **生命** ，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 `m × n` 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： `1` 即为 **活细胞** （live），或 `0` 即为 **死细胞** （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

1. 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
2. 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
3. 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
4. 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；

下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 `m x n` 网格面板 `board` 的当前状态，返回下一个状态。

来源：力扣

https://leetcode.cn/problems/game-of-life/



思路：

​		利用int类型的最低位表示是否存活，用倒数第二位表示进行原地修改后的值。

​		定义两个数组`dx`和`dy`，分别初始化为`{-1,0,1,-1,1,-1,0,1}`和`{-1,-1,-1,0,0,1,1,1}`，用于表示当前位置到它周围八个位置的具体转换方式。定义变量`i`和`j`，分别用于遍历矩阵的行和列，`k`用于遍历`dx`和`dy`数组中的八种情况。定义`nx = i+dx[k]`，`ny = j+dy[k]`，如果`nx`和`ny`都在矩阵范围内，就将`board[nx][ny]&1`的结果加到`sum`中，八个方向遍历结束后，如果`board[i][j]==1`，并且此时`sum==2`或`sum==3`，就对倒数第二位进行修改：`board[i][j] |= 2`，如果`board[i][j]==0`，`sum==3`，修改倒数第二位的值：`board[i][j] |= 2`。

​		等遍历完一遍以后，再次进行遍历，将所有的`board[i][j]`左移一位，得到最终结果。

​		