#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int cards[500005];
int main(int argc, char const *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> cards[i];
	sort(cards,cards+n);
	int m;
	cin >> m;
	for(int i = 0 ; i < m ; i++){
		int target;
		cin >> target;
		cout << upper_bound(cards,cards+n,target) - lower_bound(cards,cards+n,target) << " ";
	}
	return 0;
}

