/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define N 8
int dx[N] = { -1,-1,-1,0,0,1,1,1 };
int dy[N] = { -1,0,1,-1,1,-1,0,1 };
int** queensAttacktheKing(int** queens, int queensSize, int* queensColSize, int* king, int kingSize, int* returnSize, int** returnColumnSizes) {
    int** ans = (int**)malloc(sizeof(int*) * queensSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * queensSize);
    *returnSize = 0;
    int map[8][8] = { 0 };
    for (int i = 0; i < queensSize; i++) {
        map[queens[i][0]][queens[i][1]] = 1;
    }
    int x = king[0];
    int y = king[1];
    for (int i = 0; i < N; i++) {
        int tempx = x + dx[i];
        int tempy = y + dy[i];
        while (tempx >= 0 && tempx < 8 && tempy >= 0 && tempy < 8 && map[tempx][tempy] != 1) {
            tempx += dx[i];
            tempy += dy[i];
        }
        if (tempx < 0 || tempx >= 8 || tempy < 0 || tempy >= 8) {
            continue;
        }
        if (map[tempx][tempy] == 1) {
            ans[*returnSize] = (int*)malloc(sizeof(int) * 2);
            ans[*returnSize][0] = tempx;
            ans[*returnSize][1] = tempy;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
    }
    return ans;
}