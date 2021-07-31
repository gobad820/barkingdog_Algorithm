#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[106][106];
bool vis[105][105];
int n;
void BFS(int i, int j, int r, queue<pair<int, int> >& Q);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int height = 0;
    int ground = 1000;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ;j++){
            cin >> board[i][j];
            height = max(height,board[i][j]);
            ground = min(ground,board[i][j]);
        }
    queue<pair<int, int> > Q;
    int result = 0;
    for(int r = ground ; r < height ; r++){
        int tmp = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!vis[i][j] && board[i][j] > r){
                    BFS(i,j,r,Q);
                    tmp++;
                }
            }
        }
        result = max(tmp,result);
        for(int i = 0 ; i < n ; i++)
            fill(vis[i],vis[i] + n, 0);
    }
    if(result == 0 ) cout << 1;
    else cout << result;
    return 0;
}
void BFS(int i, int j, int r, queue<pair<int, int> >& Q){
    Q.push({i,j});
    vis[i][j] = 1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0 ; dir < 4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny] <= r || vis[nx][ny] ) continue;
            Q.push({nx,ny});
            vis[nx][ny] = 1;
        }
    }
}
