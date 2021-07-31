#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n,m;
int board[502][502];
bool vis[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int,int> > Q;
	int numberPaint = 0;
	int square = 0;
	int result = 0;
	cin >> n >> m;
	for(int a = 0 ; a < n ; a++){
		for(int b = 0 ; b < m ; b++){
			cin >> board[a][b];
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(!vis[i][j] && board[i][j] == 1){
				Q.push({i,j});
				numberPaint++;
				vis[i][j] = 1;
				square = 0;
			} 
			while(!Q.empty()){
				square++;		
				pair<int,int> cur = Q.front(); Q.pop();
				for(int dir = 0 ; dir < 4 ; dir++){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if(vis[nx][ny] || board[nx][ny] != 1) continue;
					vis[nx][ny] = 1;
					Q.push({nx,ny});
				}
			}
		result = max(square,result);
		}
	}

	cout << numberPaint << "\n" << result;
	return 0;
}
