#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
string board[105];
bool vis[105][105];
bool vis2[105][105];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0 ; i <  n ; i++)
		cin >> board[i];
	queue<pair<int, int> > Q;
	queue<pair<int, int> > Q2;
	int relm1 = 0;
	int relm2 = 0;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++){
			if(!vis[i][j]){
				Q.push({i,j});
				vis[i][j] = 1;
				relm1++;
			}
		}
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		char flag = board[cur.X][cur.Y];
		for(int dir = 0 ; dir < 4 ; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if(board[nx][ny] != flag || vis[nx][ny])continue;
			Q.push({nx,ny});
			vis[nx][ny] = 1;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(!vis2[i][j]){
				Q2.push({i,j});
				vis2[i][j] = 1;
				relm2++;
			}
		}
	}
	while(!Q2.empty()){
		auto cur = Q.front(); Q.pop();
		char flag = board[cur.X][cur.Y];
		for(int dir = 0 ; dir < 4 ; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if(board[cur.X][cur.Y] == 'R' && board[nx][ny] == 'B') continue;
			if(board[cur.X][cur.Y] == 'G' && board[nx][ny] == 'B') continue;
			if(board[cur.X][cur.Y] == 'B' && board[nx][ny] == 'G') continue;
			if(board[cur.X][cur.Y] == 'B' && board[nx][ny] == 'R') continue;
			if(vis[nx][ny]) continue;
			Q2.push({nx,ny});
			vis2[nx][ny] = 1;
		}
	}
	cout << relm1 << " " << relm2;
	return 0;
}
