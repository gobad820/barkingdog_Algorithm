#include<bits/stdc++.h>
using namespace std;

int n;
int numbers[2000005]; // 절댓값 1,000,000

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int num;
    for(int i = 0 ; i < n ; i++){
        cin >> num;
        numbers[num+1000000]++;
    }
    for(int i = 0 ; i <= 2000000 ; i++){
        while(numbers[i]--){ // numbers[i]가 0이면 false
            cout << i-1000000 << "\n";
        }
    }
    return 0;
}
