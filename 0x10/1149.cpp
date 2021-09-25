#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int r[1005];
int g[1005];
int b[1005];
int dp[1005][3];
int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n ; i++) cin >> r[i] >> g[i] >> b[i];
	dp[1][0] = r[1];
	dp[1][1] = g[1];
	dp[1][2] = b[1];
	for(int i = 2 ; i <= n ; i++){
		dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + r[i];
		dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + g[i];
		dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + b[i];
	}
	int result = 10000;
	for(int i = 0 ; i < 3 ; i++){
		result = min(result,dp[n][i]);
	}
	cout << result;
	return 0;
}

