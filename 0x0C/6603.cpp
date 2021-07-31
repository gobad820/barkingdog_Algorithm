#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int k;
int arr[20];
int numbers[20];
bool isused[20];
const int m = 6;
void func(int cur) {
    if (cur == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = 0; i < k; i++) {
        if (isused[i]) continue;
        if (cur > 0 && arr[cur - 1] > numbers[i]) continue;
        arr[cur] = numbers[i];
        isused[i] = 1;
        func(cur + 1);
        isused[i] = 0;
    }
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (1) {
        cin >> k;
        if (k == 0) break;
        fill(numbers, numbers + 20, 0);
        fill(arr, arr + 20, 0);
        fill(isused, isused + 20, 0);
        for (int i = 0; i < k; i++) cin >> numbers[i];
        func(0);
        cout << endl;
    }
    return 0;
}