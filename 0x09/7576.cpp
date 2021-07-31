#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1005][1005];
bool vis[1005][1005];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;
int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin >> board[i][j];
	queue<pair<int, int> > Q;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(board[i][j] == 1){
				Q.push({i,j});
				vis[i][j] = 1;
			}
		}
	}
	int result= 0;
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int dir = 0 ; dir < 4 ; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(board[nx][ny] != 0 || vis[nx][ny]) continue;
			if(board[nx][ny] == -1) continue;
			Q.push({nx,ny});
			vis[nx][ny] = 1;
			board[nx][ny] = board[cur.X][cur.Y] + 1;
			result = max(result, board[nx][ny]) - 1;
		}
	}
	int flag = 0;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			if(board[i][j] == 0){
			flag = 1;
				
			}
	if(flag == 1) cout << -1;
	else cout << result;
	return 0;
}
