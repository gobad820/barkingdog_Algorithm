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
    deque<int> dq;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push_back")
        {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if (s == "push_front")
        {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if (s == "pop_front")
        {
            if (dq.empty())
                cout << -1 << endl;
            else
            {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        else if (s == "pop_back")
        {
            if (dq.empty())
                cout << -1 << endl;
            else
            {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
        else if (s == "size")
        {
            cout << dq.size() << endl;
        }
        else if (s == "empty")
        {
            if (dq.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (s == "front")
        {
            if (dq.empty())
                cout << -1 << endl;
            else
                cout << dq.front() << endl;
        }
        else
        { // s == "back"
            if (dq.empty())
                cout << -1 << endl;
            else
                cout << dq.back() << endl;
        }
    }
    return 0;
}