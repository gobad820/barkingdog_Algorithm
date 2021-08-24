#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int c[2000010];
int n,m,o;
// size a, b, c;
//
int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int i = 0 ; i < m ; i++) cin >> b[i];
	o = n + m;
	int first =0; int second = 0;
	for(int i = 0 ; i < o ; i++){
		if(first == n) c[i] = b[second++];
		else if(second == m) c[i] = a[first++];
		else if(a[first] > b[second]) c[i] = b[second++];
		else c[i] = a[first++];
	}
	for(int i = 0 ; i < o ; i++) cout << c[i] << ' ';
	return 0;
}
