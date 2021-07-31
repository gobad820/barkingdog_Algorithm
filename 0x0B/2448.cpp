#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
char arr[3100][6200];
char DB[][6] = {"  *  ", " * * ", "*****"};
void Star(int n, int x, int y) {
    if (n == 1) {  // base condition
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++) arr[x + i][y + j] = DB[i][j];
        return;
    }
    Star(n / 2, x, y + 3 * n / 2);
    Star(n / 2, x + 3 * n / 2, y);
    Star(n / 2, x + 3 * n / 2, y + 3 * n);
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    Star(n / 3, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            if (arr[i][j] == '*')
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }

    return 0;
}

