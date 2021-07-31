#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int r,c;
	int n;
	cin >> n >> r >> c;
	int board[n][n];
	int x = 0; int y = 0; int start = 0; int a = 1;
	for(int i = 0 ; i < int(pow(2,n)) ; i++){
		cout << start << endl;
		board[x][y] = start++;
		cout << start << endl;
		board[x-int(pow(2,(a)-1)-1)][++y] = start++;
		a++;
		board[++x][y-int(pow(2,a+1)-1)] = start++;
		a++;
		board[x-int(pow(2,a-1)-1)][++y] = start++;
		a++;

	}
	for(int i = 0 ; i < int(pow(2,n)) ; i++){
		for(int j = 0 ; j < int(pow(2,n)); j++){
				cout <<i << "," << j << " : "  << board[i][j] << "\n";
		}
	}
	return 0;
}
