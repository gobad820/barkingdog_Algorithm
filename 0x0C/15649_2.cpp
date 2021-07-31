#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, m;
int a[10];
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    fill(a, a + n, 1);
    for (int i = 0; i < m; i++) a[i] = 0;
    do {
        for (int i = 0; i < n; i++)
            if (a[i] == 0) {
                cout << i + 1 << " ";
            }
        cout << endl;
    } while (next_permutation(a, a + n));
    return 0;
}