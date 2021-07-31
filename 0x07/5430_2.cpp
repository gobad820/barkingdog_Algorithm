#include <bits/stdc++.h>
/* header */
using namespace std;
#define endl "\n"
/* global variable */

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        deque<int> dq;
        string comm;
        cin >> comm;
        int dq_size;
        cin >> dq_size;
        string s;
        cin >> s;
        string tmp; // string으로 사용해서 +를 하면 뒤에 더해지는 효과
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == '[')
                continue;
            else if (s[i] != ',' && s[i] != ']')
                tmp += s[i];
            else if (s[i] == ',' || s[i] == ']')
            {
                if (!tmp.empty()) // string empty function
                {
                    dq.push_back(stoi(tmp)); // stoi func
                    tmp.clear();
                }
            }
        }
        bool print = true;
        bool left = true;
        for (auto c : comm)
        {
            if (c == 'R')
                left = !left;
            // 방향만 바꾼다고 생각하자
            // left는 순방향, !left는 역방향
            // empty유무 확인할 필요가 없다.
            else // c == 'D'
            {
                if (dq.empty())
                {
                    cout << "error"
                         << "\n";
                    print = false;
                    break;
                }
                else
                {
                    if (left)
                        dq.pop_front();
                    else
                        dq.pop_back();
                }
            }
        }
        if (print)
        {
            if (left)
            {
                cout << "[";
                while (!dq.empty())
                {
                    cout << dq.front();
                    dq.pop_front();
                    if (!dq.empty())
                        cout << ",";
                }
                cout << "]\n";
            }
            else
            {
                cout << "[";
                while (!dq.empty())
                {
                    cout << dq.back();
                    dq.pop_back();
                    if (!dq.empty())
                        cout << ",";
                }
                cout << "]\n";
            }
        }
    }
    return 0;
}