#include<bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
	pair<int,int> t1 = make_pair(10,13);
	pair<int,int> t2 = {4, 6}; // C++11
	cout << t2.first << " " << t2.second << endl;
	if(t2 > t1) cout << "t2 > t1" << endl;
*/

#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int,int> > Q;
	vis[0][0] = 1;
	Q.push({0,0});
	while(!Q.empty()){
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
	return 0;
}
