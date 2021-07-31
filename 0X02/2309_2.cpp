#include <bits/stdc++.h>
/* header */
using namespace std;
#define endl "\n"
int dwarf[14];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> dwarf[i];
        sum += dwarf[i];
    }
    sort(dwarf, dwarf + 9);
    int l = 0, r = 8;
    return 0;
}