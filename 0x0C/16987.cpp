#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int egg[10][2];
int cnt = 0;
void func(int cur) {
    if (cur == n) {
        int tmp = 0;
        for (int i = 0; i < n; i++)
            if (egg[i][0] <= 0) tmp++;
        cnt = max(cnt, tmp);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (cur == i) continue;
        int a = egg[cur][0];
        int b = egg[i][0];
        if (egg[cur][0] > 0 && egg[i][0] > 0) {
            egg[cur][0] -= egg[i][1];
            egg[i][0] -= egg[cur][1];
        }
        func(cur + 1);
        egg[cur][0] = a;
        egg[i][0] = b;
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> egg[i][0] >> egg[i][1];
    func(0);
    cout << cnt;
    return 0;
}