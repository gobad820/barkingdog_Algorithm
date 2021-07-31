#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
void hanoi(int a, int b, int n) {
    if (n == 1) {  // base condition
        cout << a << " " << b << endl;
        return;
    }
    hanoi(a, 6 - a - b, n - 1);
    cout << a << " " << b << endl;
    hanoi(6 - a - b, b, n - 1);
}
// void hanoi2(int a, int b, int n) {
//     if (n == 0) return;
//     hanoi2(a, 6 - a - b, n - 1);
//     cout << a << " " << b << endl;
//     hanoi2(6 - a - b, a, n - 1);
// }
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int result = 0;
    cout << (1 << n) - 1
         << endl;  // 횟수는 등비가 2인 등비수열 초항은 1이기 때문
    hanoi(1, 3, n);
    return 0;
}