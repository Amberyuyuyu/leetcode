#define N 8
int dx[N] = { 1,1,2,2,-1,-1,-2,-2 };
int dy[N] = { 2,-2,1,-1,2,-2,1,-1 };

bool checkValidGrid(int** grid, int gridSize, int* gridColSize) {
    if (grid[0][0] != 0) {
        return false;
    }
    int x = 0;
    int y = 0;
    int _x = 0;
    int _y = 0;
    int i = 0;
    int j = 0;
    int n = gridSize;
    for (i = 1; i < n * n; i++) {
        for (j = 0; j < N; j++) {
            _x = dx[j] + x;
            _y = dy[j] + y;
            if (_x >= 0 && _x < n && _y >= 0 && _y < n && grid[_x][_y] == i) {
                x = _x;
                y = _y;
                break;
            }
        }
        if (j == N) {
            return false;
        }
    }
    return true;
}