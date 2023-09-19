int directions[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool check(char** board, int boardSize, int boardColSize, int** visited, int i, int j, char* s, int sSize, int k) {
    if (board[i][j] != s[k]) {
        return false;
    }
    else if (k == sSize - 1) {
        return true;
    }
    visited[i][j] = 1;
    for (int m = 0; m < 4; m++) {
        int newi = i + directions[m][0];
        int newj = j + directions[m][1];
        if (newi >= 0 && newi < boardSize && newj >= 0 && newj < boardColSize) {
            if (visited[newi][newj] != 1) {
                bool ret = check(board, boardSize, boardColSize, visited, newi, newj, s, sSize, k + 1);
                if (ret) {
                    return true;
                }
            }
        }
    }
    visited[i][j] = 0;
    return false;
}
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int** visited = (int**)malloc(sizeof(int*) * boardSize);
    for (int i = 0; i < boardSize; i++) {
        // visited[i] = malloc(sizeof(int) * boardColSize[0]);
        // memset(visited[i], 0, sizeof(int) * boardColSize[0]);
        visited[i] = (int*)calloc(*boardColSize, sizeof(int));
    }
    int len = strlen(word);
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            bool flag = check(board, boardSize, *boardColSize, visited, i, j, word, len, 0);
            if (flag) {
                return true;
            }
        }
    }
    return false;
}