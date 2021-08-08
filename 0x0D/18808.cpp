#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m, k;
int sticker[15][15];
int board1[45][45];
int board2[45][45];

bool OOB(int a, int b) { return a < 0 || b < 0 || a >= n || b >= m; }
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        for (int a = 0; a < 15; a++) fill(sticker[a], sticker[a] + 15, 0);
        for (int a = 0; a < 45; a++) {
        }
        int r, c;
        cin >> r >> c;
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cin >> sticker[j][k];
            }
        }
        for (int j = 0; j < (n - r); j++) {
            for (int k = 0; k < (m - c); k++) {
                bool flag = 1;
                for (int l = 0; l < r; l++) {
                    for (int o = 0; l < c; o++) {
                        int nl = l + j;
                        int no = o + k;
                        if (OOB(nl, no)) {
                            l = r;
                            flag = 0;
                            for (int q = 0; q < 45; q++)
                                fill(board2[q], board2[q] + 45, 0);
                            break;
                        }
                        if (board1[nl][no] == 1 && sticker[l][o] == 1) {
                            l = r;
                            flag = 0;
                            for (int q = 0; q < 45; q++)
                                fill(board2[q], board2[q] + 45, 0);
                            break;
                        }
                        board2[nl][no] = sticker[l][o];
                    }
                }
                if (flag) {  // 스티커를 붙였으면
                    for (int l = 0; l < n; l++) {
                        for (int o = 0; o < m; o++) {
                            board1[l][o] = board2[l][o];
                        }
                    }  // board1으로 복사 후
                    j = n - r + 1;
                    break;
                    // 다음 스티커로 탈출
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << board1[i][j] << ' ';
        cout << endl;
    }
    // 스티커를 회전 없이 붙일 때의 가능한 경우의 수를 구하는 것

    // 스티커를 회전 없이 붙일 수 없을 때 회전을 하는 경우의 수를 구하는 것
    return 0;
}