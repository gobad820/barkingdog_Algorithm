#include <bits/stdc++.h>
/* header */
using namespace std;
#define endl "\n"
const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x)
{
    if (pos >= MX)
        return;
    dat[pos++] = x;
}

void pop()
{
    pos--;
}

int top()
{
    return dat[pos - 1];
}

void test()
{
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> s;
    s.push(10);
    s.push(20);
    cout << s.size() << endl;
    // pop이나 top함수는 스택이 비어있으면 런타임 에러
    return 0;
}