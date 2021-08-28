#include <bits/stdc++.h>
using namespace std;
int n;
// 1순위 길이
// 2순위 숫자인 것만 더해서 수의 총 합
// 3순위 사전순ㅓ
string a[1006];
bool cmp(const string &a, const string &b){
	if(a.length() < b.length()) return true;
	else if(a.length() == b.length()){
		int num_a = 0;
		for(auto i : a){
			if(i >= '0' && i <= '9') num_a += i-'0';
		}
		int num_b = 0;
		for(auto i : b)
			if(i >= '0' && i <= '9') num_b += i-'0';
		if(num_a < num_b) return true;
		else if(num_a == num_b){
			return a < b;
		}
		else return false;
	}
	else return false;
}
int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	sort(a,a+n,cmp);
	for(int i = 0 ; i < n ; i++) cout << a[i] << ' ' << endl;
	return 0;
}
