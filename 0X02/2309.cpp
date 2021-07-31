#include <bits/stdc++.h>
/* header */
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dwarf[15];
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> dwarf[i];
        sum += dwarf[i];
    }
    sort(dwarf, dwarf + 9);
    int flag = 0;
    for (int j = 0; j < 9; j++)
    {
        if (flag == 1)
            break;
        for (int k = j + 1; k < 9; k++)
        {
            if (sum - (dwarf[j] + dwarf[k]) == 100)
            {
                dwarf[j] = -2;
                dwarf[k] = -2;
                flag = 1;
                break;
            }
        }
    }

    for (int l = 0; l < 9; l++)
    {
        if (dwarf[l] == -2)
            continue;
        cout << dwarf[l] << "\n";
    }

    return 0;
}