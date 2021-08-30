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

/*
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
vector<pair<int, int>> cctv; // cctv의 좌표를 vector에 저장
bool OOB(int a, int b) { return a < 0 || b < 0 || a >= n || b >= m; }
//out of bounds 함수
void upd(int x, int y, int dir) {
    dir %= 4;
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if (OOB(x, y) || board2[x][y] == 6) return; // OOB거나 벽을 만나면 종료
        if (board2[x][y] != 0) continue; //이미 CCTV가 있거나 보여지고 있는 좌표
        board2[x][y] = 7; // CCTV로 보여지는 좌표 표시
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
// CCTV 좌표 표시 if (board1[i][j] == 0) mn++; // 사각지대 수 미리 집계
        }
    }
    for (int tmp = 0; tmp < (1 << 2 * cctv.size()); tmp++) { // 각각의 CCTV의
방향에 따른 경우의 수 for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
board2[i][j] = board1[i][j]; int brute = tmp; // tmp는 접근하면 X for (int i =
0; i < cctv.size(); i++) { int dir = brute % 4; // 각각의 방향으로 나누는 과정
            brute /= 4; // 다음 카메라 준비
            int x = cctv[i].X;
            int y = cctv[i].Y;
            if (board1[x][y] == 1) {
                upd(x, y, dir);
            } else if (board1[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2); // dx[], dy[]의 방향 180도 회전
            } else if (board1[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1); // 90도 회전
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
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                val += (board2[i][j] == 0);
            }
        }
        mn = min(mn, val);
    }
    cout << mn;
    return 0;
}
*/
