#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int stair;
int d[305];
int s[305];
int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> stair;
	for(int i = 1 ; i <= stair ; i++) cin >> s[i];
	d[1] = s[1];
	d[2] = s[1] + s[2];
	d[3] = max(s[1]+s[3], s[2] + s[3]);
	for(int i = 4 ; i <= stair ; i++) 
		d[i] = max(d[i-3] + s[i-1] + s[i], d[i-2] + s[i]);
	cout << d[stair];
	return 0;
}

