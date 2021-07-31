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
        for (int k = 1; k <= i - 1; k++)
            cout << " ";
        for (int j = n; j >= i; j--)
            cout
                << "*";
        cout << endl;
    }
    return 0;
}