#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef struct{
    int age;
    string name;
}Member;
vector<Member> v(100005);
Member tmp[100005];
int n;

void merge(int st, int en){
    int mid = (st+en)/2;
    int lidx = st; int ridx = mid;
    for(int i = st ; i < en ; i++){
        if(lidx == mid){
            tmp[i].age = v[ridx].age;
            tmp[i].name = v[ridx++].name;
        }
        else if(ridx == en){
            tmp[i].age = v[lidx].age;
            tmp[i].name = v[lidx++].name;
        }
        else if(v[lidx].age <= v[ridx].age){
            tmp[i].age = v[lidx].age;
            tmp[i].name = v[lidx++].name;
        }
        else{
            tmp[i].age = v[ridx].age;
            tmp[i].name = v[ridx++].name;
        }
    }
    for(int i = st; i < en ; i++){
        v[i].age = tmp[i].age;
        v[i].name = tmp[i].name;
    }
}

void mergeSort(int st, int en){
    if(st + 1 == en) return;
    mergeSort(st,mid);
    mergeSort(mid,en);
    merge(st,en);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> v[i].age >> v[i].name;
    mergeSort(0,n);
    for(int i = 0 ; i < n ; i++) cout << v[i].age << ' ' << v[i].name << endl;
    return 0;
}