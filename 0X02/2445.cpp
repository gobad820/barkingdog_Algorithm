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
    for (int i = 1; i < n; i++)
    {
        for (int k = 1; k <= i; k++)
            cout << "*";
        for (int j = n - i; j > 0; j--)
            cout << " ";
        for (int j = n - i; j > 0; j--)
            cout << " ";
        for (int k = 1; k <= i; k++)
            cout << "*";
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i + 1; j >= 1; j--)
            cout << "*";
        for (int k = i - 1; k >= 1; k--)
            cout << " ";
        for (int k = i - 1; k >= 1; k--)
            cout << " ";
        for (int j = n - i + 1; j >= 1; j--)
            cout << "*";
        cout << endl;
    }
    return 0;
}