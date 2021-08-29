#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
vector<tuple<string, int, int, int> > stud;
bool cmp(const tuple<string, int, int, int> &a, const tuple<string, int, int, int> &b){
    if(get<1>(a) > get<1>(b)) return true;
    else if(get<1>(a) == get<1>(b)){
        if(get<2>(a) < get<2>(b)) return true;
        else if(get<2>(a) == get<2>(b)) {
            if(get<3>(a) > get<3>(b)) return true;
            else if(get<3>(a) == get<3>(b)) return get<0>(a) < get<0>(b);
            else return false;
        }
        else return false;
    }
    else return false;
}
bool cmp2(const tuple<string, int, int, int> &a, const tuple<string, int, int, int> &b){
    if(get<1>(a) == get<1>(b)){
        if(get<2>(a) == get<2>(b)){
            if(get<3>(a) == get<3>(b)) return get<0>(a) < get<0>(b);
            return get<3>(a) > get<3>(b);
            }
        return get<2>(a) < get<2>(b);
    }
    return get<1>(a) > get<1>(b);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string name; int k; int e; int m;
        cin >> name >> k >> e >> m;
        stud.emplace_back(name,k,e,m);
    }
    sort(stud.begin(), stud.end(), cmp2);
    for(auto i : stud) cout << get<0>(i) << endl;
    return 0;
}

