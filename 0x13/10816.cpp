#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int cards[500005];
int Upper(int target, int len){
	int st = 0;
	int en = len;
	while(st < en){
		int mid = (st+en)/2;
		if(target < cards[mid]) en = mid;
		else st = mid + 1;
	}
	return st;
}
int Lower(int target, int len){
	int st = 0;
	int en = len;
	while(st < en){
		int mid = (st+en)/2;
		if(target <= cards[mid]) en = mid;
		else st = mid + 1;
	}
	return st;
}
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
		cout << Upper(target,n) - Lower(target,n) << " ";
	}
	return 0;
}

