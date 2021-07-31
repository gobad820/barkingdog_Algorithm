
#include <bits/stdc++.h>
using namespace std;
int dist[100005];
int dx[2] = {-1,1};
int n,k;
int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	fill(dist,dist+100000,-1);
	queue<int> Q;
	Q.push(n);
	dist[n] = 0;
	while(dist[k] == -1){
		auto cur = Q.front(); Q.pop();
		if(cur * 2 <= 100000){
			if(dist[cur*2] == -1){
				Q.push(cur*2);
				dist[cur*2] = dist[cur];
			}
		}
		if(cur - 1 >= 0){
			if(dist[cur-1] == -1){
				Q.push(cur-1);
				dist[cur-1] = dist[cur]+1;
			}
		}
		if(cur + 1 <= 100000){
			if(dist[cur+1] == -1){
				Q.push(cur+1);
				dist[cur+1] = dist[cur]+1;
			}
		}
	}
	cout << dist[k];
	return 0;
}
