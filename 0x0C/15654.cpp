#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, m;
int numbers[10];
int arr[10];
bool isused[10];
void func(int cur) {
    if (cur == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!isused[i]) {
            arr[cur] = numbers[i];
            isused[i] = 1;
            func(cur + 1);
            isused[i] = 0;
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