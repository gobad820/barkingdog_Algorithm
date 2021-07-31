#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void star(int n, int x, int y) {
    if ((x / n) % 3 == 1 && (y / n) % 3 == 1)
        cout << " ";
    else {
        if (n / 3 == 0)
            cout << "*";  // n == 1;
        else
            star(n / 3, x, y);
    }
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) star(n, i, j);
        cout << endl;
    }
    return 0;
}