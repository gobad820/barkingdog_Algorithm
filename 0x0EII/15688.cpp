#include<bits/stdc++.h>
using namespace std;

int n;
int numbers[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int num;
    for(int i = 0 ; i < n ; i++){
        cin >> num;
        numbers[num]++;
    }
    for(int i = 0 ; i < n ; i++){
        if(numbers[i] == 0) continue;
        while(numbers[i] > 0){
            cout << i << endl;
            numbers[i]--;
        }
    }
    return 0;
}