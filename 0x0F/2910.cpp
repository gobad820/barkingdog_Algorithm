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
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define X first
#define Y second
int n,c;
int arr[1005];
vector<pair<int ,int> > vec;
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.Y > b.Y;
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
    for(int i = 0 ; i < n ; i++) vec.push_back({arr[i],arr2[arr[i]]});
    stable_sort(vec.begin(),vec.end(),cmp);
    for(int i = 0 ; i < n ; i++) cout << vec[i].X <<  ' ' << endl;
    // c = maximum of numbers
}
