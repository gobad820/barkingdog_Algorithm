#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int cnt = 0;
bool isused1[40];
bool isused2[40];
bool isused3[40];
void func(int cur) {
    if (cur == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isused1[i] || isused2[cur + i] || isused3[cur - i + n - 1])
            continue;
        isused1[i] = 1;
        isused2[cur + i] = 1;
        isused3[cur - i + n - 1] = 1;
        func(cur + 1);
        isused1[i] = 0;
        isused2[cur + i] = 0;
        isused3[cur - i + n - 1] = 0;
    }
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    func(0);
    cout << cnt;
    return 0;
}