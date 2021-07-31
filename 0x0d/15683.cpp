#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, m;
int board[10][10];
void bigEye5() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 5) {
                for (int x = i - 1; x >= 0; x--) {
                    if (board[x][j] == 6) break;
                    if (board[x][j] == 0) board[x][j] = -1;
                }
                for (int x2 = i + 1; x2 < n; x2++) {
                    if (board[x2][j] == 6) break;
                    if (board[x2][j] == 0) board[x2][j] = -1;
                }
                for (int y = j - 1; y >= 0; y--) {
                    if (board[i][y] == 6) break;
                    if (board[i][y] == 0) board[i][y] = -1;
                }
                for (int y2 = j + 1; y2 < m; y2++) {
                    if (board[i][y2] == 6) break;
                    if (board[i][y2] == 0) board[i][y2] = -1;
                }
            }
        }
    }
}
void bigEye4() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 4) {
                int copy_board[4][10][10];
                for (int a = 0; a < 4; a++) {
                    for (int b = 0; b < n; b++)
                        for (int c = 0; c < m; c++)
                            copy_board[a][b][c] = board[b][c];
                }
                // for (int y = 0; y < m; y++) {
                //     if (copy_board[0][i][y] == 6) break;
                //     if (copy_board[0][i][y] == 0) copy_board[0][i][y] = -1;
                //     if (copy_board[1][i][y] == 6) break;
                //     if (copy_board[1][i][y] == 0) copy_board[1][i][y] = -1;
                // }
                for (int y2 = j - 1; y2 >= 0; y2--) {
                    if (copy_board[2][i][y2] == 6) break;
                    if (copy_board[2][i][y2] == 0) copy_board[2][i][y2] = -1;
                }
                for (int y2 = j - 1; y2 >= 0; y2--) {
                    if (copy_board[0][i][y2] == 6) break;
                    if (copy_board[0][i][y2] == 0) copy_board[0][i][y2] = -1;
                }
                for (int y2 = j - 1; y2 >= 0; y2--) {
                    if (copy_board[1][i][y2] == 6) break;
                    if (copy_board[1][i][y2] == 0) copy_board[1][i][y2] = -1;
                }
                for (int y3 = j + 1; y3 < m; y3++) {
                    if (copy_board[3][i][y3] == 6) break;
                    if (copy_board[3][i][y3] == 0) copy_board[3][i][y3] = -1;
                }
                for (int y3 = j + 1; y3 < m; y3++) {
                    if (copy_board[0][i][y3] == 6) break;
                    if (copy_board[0][i][y3] == 0) copy_board[0][i][y3] = -1;
                }
                for (int y3 = j + 1; y3 < m; y3++) {
                    if (copy_board[1][i][y3] == 6) break;
                    if (copy_board[1][i][y3] == 0) copy_board[1][i][y3] = -1;
                }
                // for (int x = 0; x < n; x++) {
                //     if (copy_board[2][x][j] == 6) break;
                //     if (copy_board[2][x][j] == 0) copy_board[2][x][j] = -1;
                //     if (copy_board[3][x][j] == 6) break;
                //     if (copy_board[3][x][j] == 0) copy_board[3][x][j] = -1;
                // }
                for (int x2 = i - 1; x2 >= 0; x2--) {
                    if (copy_board[0][x2][j] == 6) break;
                    if (copy_board[0][x2][j] == 0) copy_board[0][x2][j] = -1;
                }
                for (int x2 = i - 1; x2 >= 0; x2--) {
                    if (copy_board[2][x2][j] == 6) break;
                    if (copy_board[2][x2][j] == 0) copy_board[2][x2][j] = -1;
                }
                for (int x2 = i - 1; x2 >= 0; x2--) {
                    if (copy_board[3][x2][j] == 6) break;
                    if (copy_board[3][x2][j] == 0) copy_board[3][x2][j] = -1;
                }
                for (int x3 = i + 1; x3 < n; x3++) {
                    if (copy_board[1][x3][j] == 6) break;
                    if (copy_board[1][x3][j] == 0) copy_board[1][x3][j] = -1;
                }
                for (int x3 = i + 1; x3 < n; x3++) {
                    if (copy_board[2][x3][j] == 6) break;
                    if (copy_board[2][x3][j] == 0) copy_board[2][x3][j] = -1;
                }
                for (int x3 = i + 1; x3 < n; x3++) {
                    if (copy_board[3][x3][j] == 6) break;
                    if (copy_board[3][x3][j] == 0) copy_board[3][x3][j] = -1;
                }
                int typeing[4] = {0, 0, 0, 0};
                for (int a = 0; a < 4; a++) {
                    for (int b = 0; b < n; b++) {
                        for (int c = 0; c < m; c++) {
                            if (copy_board[a][b][c] == -1) typeing[a]++;
                        }
                    }
                }
                int result = -1;
                int typeing2 = -1;
                for (int p = 0; p < 4; p++) {
                    if (typeing2 < typeing[p]) {
                        result = p;
                        typeing2 = typeing[p];
                    }
                }
                for (int a = 0; a < n; a++) {
                    for (int b = 0; b < m; b++) {
                        board[a][b] = copy_board[result][a][b];
                    }
                }
            }
        }
    }
}
void bigEye3() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 3) {
                int copy_board[4][10][10];
                for (int a = 0; a < 4; a++) {
                    for (int b = 0; b < n; b++)
                        for (int c = 0; c < m; c++)
                            copy_board[a][b][c] = board[b][c];
                }

                for (int x = i - 1; x >= 0; x--) {
                    if (copy_board[0][x][j] == 6) break;
                    if (copy_board[0][x][j] == 0) copy_board[0][x][j] = -1;
                }
                for (int x = i - 1; x >= 0; x--) {
                    if (copy_board[1][x][j] == 6) break;
                    if (copy_board[1][x][j] == 0) copy_board[1][x][j] = -1;
                }
                for (int x2 = i + 1; x2 < n; x2++) {
                    if (copy_board[2][x2][j] == 6) break;
                    if (copy_board[2][x2][j] == 0) copy_board[2][x2][j] = -1;
                }
                for (int x2 = i + 1; x2 < n; x2++) {
                    if (copy_board[3][x2][j] == 6) break;
                    if (copy_board[3][x2][j] == 0) copy_board[3][x2][j] = -1;
                }
                for (int y = j + 1; y < m; y++) {
                    if (copy_board[0][i][y] == 6) break;
                    if (copy_board[0][i][y] == 0) copy_board[0][i][y] = -1;
                }
                for (int y = j + 1; y < m; y++) {
                    if (copy_board[3][i][y] == 6) break;
                    if (copy_board[3][i][y] == 0) copy_board[3][i][y] = -1;
                }
                for (int y2 = j - 1; y2 >= 0; y2--) {
                    if (copy_board[1][i][y2] == 6) break;
                    if (copy_board[1][i][y2] == 0) copy_board[1][i][y2] = -1;
                }
                for (int y2 = j - 1; y2 >= 0; y2--) {
                    if (copy_board[2][i][y2] == 6) break;
                    if (copy_board[2][i][y2] == 0) copy_board[2][i][y2] = -1;
                }
                int typeing[4] = {0, 0, 0, 0};
                for (int a = 0; a < 4; a++) {
                    for (int b = 0; b < n; b++) {
                        for (int c = 0; c < m; c++) {
                            if (copy_board[a][b][c] == -1) typeing[a]++;
                        }
                    }
                }
                int result = -1;
                int typeing2 = -1;
                for (int p = 0; p < 4; p++) {
                    if (typeing2 < typeing[p]) {
                        result = p;
                        typeing2 = typeing[p];
                    }
                }
                for (int a = 0; a < n; a++) {
                    for (int b = 0; b < m; b++) {
                        board[a][b] = copy_board[result][a][b];
                    }
                }
            }
        }
    }
}
void bigEye2() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 2) {
                int copy_board[2][10][10];
                for (int a = 0; a < 2; a++) {
                    for (int b = 0; b < n; b++)
                        for (int c = 0; c < m; c++)
                            copy_board[a][b][c] = board[b][c];
                }
                for (int x = i - 1; x >= 0; x--) {
                    if (copy_board[0][x][j] == 6) break;
                    if (copy_board[0][x][j] == 0) copy_board[0][x][j] = -1;
                }
                for (int x2 = i + 1; x2 < n; x2++) {
                    if (copy_board[0][x2][j] == 6) break;
                    if (copy_board[0][x2][j] == 0) copy_board[0][x2][j] = -1;
                }
                for (int y = j - 1; y >= 0; y--) {
                    if (copy_board[1][i][y] == 6) break;
                    if (copy_board[1][i][y] == 0) copy_board[1][i][y] = -1;
                }
                for (int y2 = j + 1; y2 < m; y2++) {
                    if (copy_board[1][i][y2] == 6) break;
                    if (copy_board[1][i][y2] == 0) copy_board[1][i][y2] = -1;
                }
                int typeing[2] = {0, 0};
                for (int a = 0; a < 2; a++) {
                    for (int b = 0; b < n; b++) {
                        for (int c = 0; c < m; c++) {
                            if (copy_board[a][b][c] == -1) typeing[a]++;
                        }
                    }
                }
                int result = -1;
                int typeing2 = -1;
                for (int p = 0; p < 2; p++) {
                    if (typeing2 < typeing[p]) {
                        result = p;
                        typeing2 = typeing[p];
                    }
                }
                for (int a = 0; a < n; a++) {
                    for (int b = 0; b < m; b++) {
                        board[a][b] = copy_board[result][a][b];
                    }
                }
            }
        }
    }
}
void bigEye1() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                int copy_board[4][10][10];
                for (int a = 0; a < 4; a++) {
                    for (int b = 0; b < n; b++)
                        for (int c = 0; c < m; c++)
                            copy_board[a][b][c] = board[b][c];
                }
                for (int y = j + 1; y < m; y++) {
                    if (copy_board[0][i][y] == 6) break;
                    if (copy_board[0][i][y] == 0) copy_board[0][i][y] = -1;
                }
                for (int x = i - 1; x >= 0; x--) {
                    if (copy_board[1][x][j] == 6) break;
                    if (copy_board[1][x][j] == 0) copy_board[1][x][j] = -1;
                }
                for (int y2 = j - 1; y2 >= 0; y2--) {
                    if (copy_board[2][i][y2] == 6) break;
                    if (copy_board[2][i][y2] == 0) copy_board[2][i][y2] = -1;
                }
                for (int x2 = i + 1; x2 < n; x2++) {
                    if (copy_board[3][x2][j] == 6) break;
                    if (copy_board[3][x2][j] == 0) copy_board[3][x2][j] = -1;
                }
                int typeing[4] = {0, 0, 0, 0};
                for (int a = 0; a < 4; a++) {
                    for (int b = 0; b < n; b++) {
                        for (int c = 0; c < m; c++) {
                            if (copy_board[a][b][c] == -1) typeing[a]++;
                        }
                    }
                }
                int result = -1;
                int typeing2 = -1;
                for (int p = 0; p < 4; p++) {
                    if (typeing2 < typeing[p]) {
                        result = p;
                        typeing2 = typeing[p];
                    }
                }
                for (int a = 0; a < n; a++) {
                    for (int b = 0; b < m; b++) {
                        board[a][b] = copy_board[result][a][b];
                    }
                }
            }
        }
    }
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];
    bigEye5();
    bigEye4();
    bigEye3();
    bigEye2();
    bigEye1();
    int new_result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << ' ';
            if (board[i][j] == 0) new_result++;
        }
        cout << endl;
    }
    cout << new_result;
    return 0;
}