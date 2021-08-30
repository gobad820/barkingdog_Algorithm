#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n,c;
int nums[1005];
vector<int> order;
int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> c;
	for(int i = 0 ; i < n ; i++) cin >> nums[i];
	sort(nums,nums+n);
	for(int i = 0 ; i < n ; i++) cout << nums[i] << ' ';
	return 0;
}

