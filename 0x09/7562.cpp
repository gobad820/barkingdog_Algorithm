#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int tc;
int n;
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
int board[305][305];
int dist[305][305];
int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tc;
	while(tc--){
		cin >> n;
		for(int i = 0 ; i < n ; i++)
			fill(dist[i], dist[i]+n, -1);
		int x1,y1,x2,y2;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		queue<pair<int, int> > Q;
		Q.push({x1,y1});
		dist[x1][y1] = 0;
		int result = 0;
		while(!Q.empty()){
			auto cur = Q.front(); Q.pop();
			if(cur.X == x2 && cur.Y == y2){
				result = dist[cur.X][cur.Y];
				break;
			}
			for(int dir = 0 ; dir < 8 ; dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx < 0 || ny <0 || nx >= n || ny > n) continue;
				if(dist[nx][ny] >= 0 || board[nx][ny] != 0) continue;
				Q.push({nx,ny});
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			}
		}
		cout << result << "\n";
	}
	return 0;
}
