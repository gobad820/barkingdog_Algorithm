#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int t,n,m;
int a[20005];
int b[20005];

bool cmp(const int &a, const int &b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0 ; i < n ; i++) cin >> a[i];
        for(int i = 0 ; i < m ; i++) cin >> b[i];
        sort(a,a+n,cmp);
        sort(b,b+m,cmp);
        int result = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(a[i] > b[j]){ 
                    result += m - j;
                    break;
                }
        cout << result << endl;
    }
    return 0;
}
