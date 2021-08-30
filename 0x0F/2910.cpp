#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define X first
#define Y second
int n,c;
int arr[1005];
vector<pair<int ,int> > vec(1005);
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.Y > b.Y;
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
    stable_sort(vec.begin(),vec.end(),cmp);
    for(int i = 0 ; i < n ; i++){
        while(vec[i].Y--) cout << vec[i].X << ' ';
    }
    return 0;
    // c = maximum of numbers
}
