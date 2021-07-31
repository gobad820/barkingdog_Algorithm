#include <bits/stdc++.h>
using namespace std;
int dist[200005];
int n,k;
int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	fill(dist,dist+200005,-1);
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	while(dist[k] == -1){
		auto cur = q.front(); q.pop();
		for(int nxt : {cur-1,cur+1,cur*2}){
			if(nxt < 0 || nxt > 100000) continue;
			if(dist[nxt] != -1) continue;
			dist[nxt] = dist[cur]+1;
			q.push(nxt);
		}
	}
	cout << dist[k];
	return 0;
}
