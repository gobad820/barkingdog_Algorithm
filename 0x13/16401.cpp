#include<iostream>
typedef long long ll;
int m,n;
int snacks[1000005];
bool solve(ll x){
	ll crnt = 0;
	for(int i = 0 ; i < n ; i++) crnt += snacks[i] / x;
	return crnt >= m;
}
int main(void){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> m >> n;
	for(int i = 0 ; i < n ; i++) std::cin >> snacks[i];
	ll st = 0;
	ll en = 1000000000;
	ll mid2;
	while(st < en){
		ll mid = (st+en+1)/2;
		if(solve(mid)) st = mid;
		else en = mid - 1;
		mid2 = mid;
	}
	std::cout << st;
	return 0 ;
}
