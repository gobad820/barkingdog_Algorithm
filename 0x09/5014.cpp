#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define INF 999999999
int dist[MAX];
int f,s,g,u,d;
int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> f >> s >> g >> u >> d;
	fill(dist,dist+MAX,INF);
	int result = 0;
	int res;
	if(g > s){
		if(u == 0){
			cout << "use the stiars";
			return 0;
		}
		res = (g-s)/u;
		s += res * u;
	}
	else if(g < s){
		if(d == 0){
			cout << "use the stiars";
			return 0;
		}
		res = (s-g)/d;
		s -= res * d;
	}
	queue<int> Q;
	Q.push(s);
	dist[s] = 0;
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		if(cur == g){
			result = dist[cur];
			break;
		}
		if(dist[cur+u] > dist[cur] && cur + u <= f){
			Q.push(cur+u);
			dist[cur+u] = dist[cur]+1;
		}
		if(dist[cur-d] > dist[cur] && cur - d > 0){
			Q.push(cur-d);
			dist[cur-d] = dist[cur]+1;
		}
	}
	result += res;
	cout << result;
	return 0;
}
