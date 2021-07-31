#include <bits/stdc++.h>
/* header */
using namespace std;
#define endl "\n"
int n;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
            cout << " ";
        for (int k = 2 * (n - i) + 1; k >= 1; k--)
            cout << "*";
        cout << endl;
    }
    return 0;
}