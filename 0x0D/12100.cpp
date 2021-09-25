#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int board[30][30];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void check(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = dx[i] + x;
    int ny = dy[i] + y;
    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
    if (board[nx][ny] == board[x][y]) {  // 같은 수 나왔을때
    }
  }
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  int result = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) result = max(result, board[i][j]);
  cout << result;
  return 0;
}