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
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);
    while (q.size() != 1)
    {
        q.pop();
        int num = q.front();
        q.pop();
        q.push(num);
    }
    cout << q.front();
    return 0;
}