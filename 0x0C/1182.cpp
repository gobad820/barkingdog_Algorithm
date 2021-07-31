#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, s;
int arr[20];
int cnt = 0;
void func(int cur, int tot) {
    if (cur == n) {
        if (tot == s) cnt++;
        return;
    }
    func(cur + 1, tot);
    func(cur + 1, arr[cur] + tot);
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (s == 0) cnt--;
    func(0, 0);
    cout << cnt;
    return 0;
}