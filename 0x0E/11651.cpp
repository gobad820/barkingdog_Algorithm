#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef struct{
    int x;
    int y;
}dots;

int n;
vector<dots> v(100005);
dots tmp[100005];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> v[i].x >> v[i].y;
    mergeSort(0,n);
    for(int i = 0 ; i < n ; i++) cout << v[i].x << ' ' << v[i].y << endl;
    return 0;
}