#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, m;
int numbers[10];
int arr[10];
bool isused[10];
void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!isused[i]) {
            arr[k] = numbers[i];
            // for (int j = 0; j < n; j++) {
            // if (numbers[i] >= numbers[j]) isused[j] = 1;
            // }
            func(k + 1);
            // for (int j = 0; j < n; j++) {
            // if (numbers[i] >= numbers[j]) isused[j] = 0;
            // }
        }
    }
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> numbers[i];
    sort(numbers, numbers + n);
    func(0);
    return 0;
}