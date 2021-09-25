#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define X first
#define Y second
int n,c;
int arr[1005];
vector<pair<int ,int> > vec;
vector<tuple<int, int, int> > nums;
// 숫자 빈도 등장순서
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.Y > b.Y;
}
bool cmp2(const tuple<int, int, int> &a, const tuple<int, int, int> &b){
	if(get<1>(a) == get<1>(b))
		return get<2>(a) < get<2>(b);
	return get<1>(a) < get<2>(b);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    int arr2[c+5];
    fill(arr2,arr2+c+5,0);
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
        arr2[arr[i]]++;
    }
	for(int i = 1 ; i <= c ; i++){
		cout << arr2[i] << endl;
	}
    for(int i = 0; i < n ; i++) {
		nums.emplace_back(arr[i],arr2[arr[i]],i);
	}
	stable_sort(nums.begin(),nums.end(),cmp2);
    for(auto i : nums){
		cout << get<0>(i);
	}
	return 0;
			// c = maximum of numbers
}
