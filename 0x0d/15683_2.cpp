#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define X first
#define Y second

int n, m;
int board1[10][10];
int board2[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > cctv;

bool OOB(int a, int b) { return a < 0 || b < 0 || a >= n || b >= m; }

void upd(int x, int y, int dir) {
    dir %= 4;
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if (OOB(x, y) || board2[x][y] == 6) return;
        if (board2[x][y] != 0) continue;
        board2[x][y] = 7;
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int mn = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board1[i][j];
            if (board1[i][j] != 0 && board1[i][j] != 6) cctv.push_back({i, j});
            if (board1[i][j] == 0) mn++;
        }
    }
    for (int tmp = 0; tmp < (1 << 2 * cctv.size()); tmp++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) board2[i][j] = board1[i][j];
        int brute = tmp;
        for (int i = 0; i < cctv.size(); i++) {
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].X;
            int y = cctv[i].Y;
            if (board1[x][y] == 1) {
                upd(x, y, dir);
            } else if (board1[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2);
            } else if (board1[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
            } else if (board1[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
            } else {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }
        }
        int val = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) val += (board2[i][j] == 0);
        mn = min(val, mn);
    }
    cout << mn;
    return 0;
}