#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[105][105];
int dist[105][105];
int n;
int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> board[i][j];
	for(int i = 0 ; i < n ; i++)
		fill(dist[i],dist[i]+n,-1);

	return 0;
}
