#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int cards[500005];
int BinarySearch(int target){
	int st = 0;
	int en = n-1;
	while(st <= en){
		int mid = (st+en)/2;
		if(target < cards[mid]) en = mid - 1;
		else if(target > cards[mid]) st = mid + 1;
		else return 1;
	}
	return 0;
}
int main(int argc, char const *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> cards[i];
	sort(cards,cards+n);
	int m;
	cin >> m;
	for(int i = 0 ; i < m ; i ++){
		int tmp;
		cin >> tmp;
		cout << BinarySearch(tmp) << " ";
	}
	return 0;
}

