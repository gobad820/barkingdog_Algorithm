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
        // if (cur > 0 && arr[cur - 1] > numbers[i]) continue;
        arr[cur] = numbers[i];
        func(cur + 1);
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