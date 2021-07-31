#include <bits/stdc++.h>
/* header */
using namespace std;

int t;
int call[25];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++)
        cin >> call[i];

    int pay;
    int flag;
    int pay_y = 0;
    int pay_m = 0;
    for (int i = 0; i < t; i++)
    {
        pay_y += (call[i] / 30 + 1) * 10;
        pay_m += (call[i] / 60 + 1) * 15;
        if (pay_y > pay_m)
        {
            flag = 1;
            pay = pay_m;
        }
        else if (pay_y < pay_m)
        {
            flag = 2;
            pay = pay_y;
        }
        else
        {
            flag = 0;
            pay = pay_m;
        }
    }
    if (flag == 0)
        cout << "Y"
             << " "
             << "M"
             << " ";
    else if (flag == 1)
        cout << "M"
             << " ";
    else if (flag == 2)
        cout << "Y"
             << " ";
    cout << pay;

    return 0;
}