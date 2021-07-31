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
    stack<int> s;
    while (n--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push")
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (cmd == "pop")
        {
            if (s.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if (cmd == "empty")
        {
            if (s.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (cmd == "top")
        {
            if(s.empty())
                cout << -1 << endl;
            else
                cout << s.top() << endl;
        }
        else // cmd == "size"
        {
            cout << s.size() << endl;
        }
    }
    return 0;
}