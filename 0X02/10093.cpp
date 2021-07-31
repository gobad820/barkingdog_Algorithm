#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll a, b;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    if (a > b + 1)
    {
        cout << a - b - 1 << "\n";
        for (ll i = b + 1; i < a; i++)
            cout << i << " ";
    }
    else if (a < b + 1)
    {
        cout << b - a - 1 << "\n";
        for (ll i = a + 1; i < b; i++)
            cout << i << " ";
    }
    else
    {
        cout << 0;
    }
    return 0;
}
