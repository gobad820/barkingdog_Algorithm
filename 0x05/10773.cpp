#include <bits/stdc++.h>
/* header */
using namespace std;
#define endl "\n"
int k;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    stack<int> s;
    while (k--)
    {
        int n;
        cin >> n;
        if (n == 0) // 최근에 쓴 수를 지운다.
            s.pop();
        else // 해당 수를 쓴다
            s.push(n);
    }
    unsigned int result = 0;
    int money_size = s.size();
    for (int i = 0; i < money_size; i++)
    {
        result += s.top();
        if (!s.empty())
            s.pop();
    }
    cout << result;
    return 0;
}