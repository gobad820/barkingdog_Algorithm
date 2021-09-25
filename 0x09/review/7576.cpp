#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define X first
#define Y second

int m,n;
int board[1005][1005];
int vis[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > Q;

int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> board[i][j];
			if(board[i][j] == 1){
				Q.push({i,j});
				vis[i][j] = 1;
			}
		}
	}
	int result = 0;
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int i = 0 ; i < 4 ; i++){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(board[nx][ny] == -1 || vis[nx][ny]) continue;
			Q.push({nx,ny});
			vis[nx][ny] = 1;
			board[nx][ny] = board[cur.X][cur.Y] + 1;
			result = max(result, board[nx][ny]) -1;
		}
	}
	bool flag = 0;
	for(int i = 0 ; i < n ; i++){
		if(flag) break;
		for(int j = 0 ; j < m ; j++){
			if(board[i][j] == 0) {
				flag = 1;
				break;
			}
		}
	}
	if(flag) cout << -1;
	else cout << result;
	return 0;
}

