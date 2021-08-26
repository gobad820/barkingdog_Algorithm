#include<bits/stdc++.h>
using namespace std;

int n;
int numbers[2000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int num;
    int maxnum = -1;
    for(int i = 0 ; i < n ; i++){
        cin >> num;
        numbers[num+1000000]++;
        maxnum = max(maxnum,num);
    }
    for(int i = 0 ; i <= maxnum ; i++){
        if(numbers[i] == 0) continue;
        while(numbers[i] > 0){
            cout << i << endl;
            numbers[i]--;
        }
    }
    return 0;
}
