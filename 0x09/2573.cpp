#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[305][305];
bool vis[305][305];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;
void BFS(int i, int j, queue<pair<int, int> >& Q){
	Q.push({i,j});
	vis[i][j] = 1;
	for(int k = 0 ; k < 4;  k++){
		if(board[i+dx[k]][j+dy[k]] == 0)
			board[i][j]--;
			if(board[i][j] < 0){
				board[i][j] = 0;
				break;
			}
	}
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int dir = 0 ; dir < 4 ; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(board[nx][ny] == 0 && vis[nx][ny]) continue;
			Q.push({nx,ny});
			vis[nx][ny] = 1;
			int ocean = 0;
			for(int k = 0 ; k < 4; k++){
				if(board[cur.X+dx[k]][cur.Y+dy[k]] == 0){
					board[cur.X][cur.Y]--;
					if(board[cur.X][cur.Y] < 0){
						board[cur.X][cur.Y] = 0;
						break;
					}
				}
			}
		}
	}
}
int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int height = 0;
	pair<int, int> h;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++){
			cin >> board[i][j];
			if(board[i][j] > height)
				h = {i,j};
		}
	queue<pair<int, int> > Q;
	pair<int, int> result = {0,0};
	int flag =0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(board[i][j] != 0 && !vis[i][j]){
				BFS(i,j,Q);
				result.X++;
			}
		}
	}
	cout << result.X << "\n";
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout << board[i][j] << " ";
		}cout << "\n";
	}
	while(true){
		flag = 0;
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
				if(board[i][j] != 0){
					flag = 1;
				}
		cout << flag  << "\n";
		if(flag == 0) break;	
		cout << 1 << "\n";
		for(int i = 0 ; i < n ; i++)
			fill(vis[i], vis[i]+m, 0);
		int relm = 0;	
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(board[i][j] != 0 && !vis[i][j]){
					BFS(i,j,Q);
					relm++;
				}
			}
		}
		cout << result.X << " "<< relm;
		if(result.X < relm) result.Y++;
		result.X = max(result.X, relm);
	}
	cout << result.Y << result.X;
	return 0;
}
