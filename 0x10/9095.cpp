#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int t,n;
int d[15];
int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for(int i = 4 ; i <=11 ; i++){
		d[i] = d[i-1]+d[i-2]+d[i-3];
	}
	while(t--){
		cin >> n;
		cout << d[n] << endl;	
	}
	return 0;
}

