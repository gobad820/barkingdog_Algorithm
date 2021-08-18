#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, m, k, r, c;
int board[50][50];
int stckr[15][15];

bool pastable(int x, int y) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (board[i + x][j + y] == 1 && stckr[i][j] == 1) return false;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (stckr[i][j] == 1) board[i + x][j + y] = 1;
    return true;
}

void rotate() {
    int tmp[12][12];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) tmp[i][j] = stckr[i][j];

    for (int i = 0; i < c; i++)  // 틀을 회전했으므로 행과 열이 서로 바뀜
        for (int j = 0; j < r; j++) stckr[i][j] = tmp[r - 1 - j][i];

    swap(r, c);
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) cin >> stckr[i][j];

        for (int rot = 0; rot < 4; rot++) {
            bool is_paste = false;  // 해당 스티커를 붙였는가?
            for (int x = 0; x <= n - r; x++) {
                if (is_paste) break;
                for (int y = 0; y <= m - c; y++) {
                    if (pastable(x, y)) {
                        is_paste = true;
                        break;
                    }
                }
            }
            if (is_paste) break;
            rotate();
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cnt += board[i][j];
    cout << cnt << '\n';
    return 0;
}