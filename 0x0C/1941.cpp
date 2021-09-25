#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define X first
#define Y second
char board[8][8];
bool isused[8][8];
string tmp;
vector<string> V;
int cnt = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void func(int cur, int x, int y) {
  if (cur == 7) {
    int y_number = 0;
    for (int i = 0; i < 7; i++)
      if (tmp[i] == 'Y') y_number++;
    bool flag = 0;
    if (y_number <= 3) {
      for (int j = 0; j < V.size(); j++) {
        if (V.at(j) == tmp) {
          flag = 1;
          break;
        }
      }
      if (!flag) {
        cnt++;
        V.push_back(tmp);
        cout << tmp << endl;
      }
    }
    return;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
    tmp += board[nx][ny];
    isused[nx][ny] = 1;
    func(cur + 1, nx, ny);
    tmp.pop_back();
    isused[nx][ny] = 0;
  }
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string line;
  queue<pair<int, int> > Q;
  for (int i = 0; i < 5; i++) {
    cin >> line;
    for (int j = 0; j < 5; j++) {
      board[i][j] = line[j];
      if (board[i][j] == 'S') Q.push({i, j});
    }
  }
  // 중복이 될텐데;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      isused[i][j] = 1;
      func(0, i, j);
      isused[i][j] = 0;
    }
  cout << cnt;
  return 0;
}