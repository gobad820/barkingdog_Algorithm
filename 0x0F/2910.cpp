#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define X first
#define Y second
int n,c;
int arr[1005];
<<<<<<< HEAD
vector<pair<int ,int> > vec;
vector<tuple<int, int, int> > nums;
// 숫자 빈도 등장순서
=======
vector<pair<int ,int> > vec(1005);
>>>>>>> 15205b817d9954e1e4018055e43b309d060af375
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
    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        bool flag1 = false;
        for(int j = 0 ; j < i ; j++){
            if(arr[j] == a){
                flag1 = true;
                break;
            }
        }
        if(!flag1) arr[i] = a;
        if(i == 0){
            vec[i].X = a;
            vec[i].Y = 1;
        }
        else{
            bool flag = false;
            int j = 0;
            for(j = 0 ; j < i ; j++){
                if(arr[j] == a){
                    flag = true;
                    break;
                }
            }
            if(flag){// num exsit
                vec[j].Y++;
            }
            else{
                vec[i].X = a;
                vec[i].Y = 1;
            }
        }

    }
<<<<<<< HEAD
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
=======
    stable_sort(vec.begin(),vec.end(),cmp);
    for(int i = 0 ; i < n ; i++){
        while(vec[i].Y--) cout << vec[i].X << ' ';
    }
    return 0;
    // c = maximum of numbers
>>>>>>> 15205b817d9954e1e4018055e43b309d060af375
}
