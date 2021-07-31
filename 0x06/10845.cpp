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
    while (n--)
    {
        string comm;
        cin >> comm;
        if (comm == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else if (comm == "pop")
        {
            if (q.empty())
                cout << -1 << endl;
            else
            {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (comm == "size")
        {
            cout << q.size() << endl;
        }
        else if (comm == "empty")
        {
            if (q.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (comm == "front")
        {
            if (q.empty())
                cout << -1 << endl;
            else
                cout << q.front() << endl;
        }
        else
        { // comm == "back"
            if (q.empty())
                cout << -1 << endl;
            else
                cout << q.back() << endl;
        }
    }
    return 0;
}