#include <bits/stdc++.h>
/* header */
using namespace std;
#define endl "\n"
const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX;
int tail = MX;

void push_front(int x)
{
    dat[--head] = x;
}
void push_back(int x)
{
    dat[tail++] = x;
}
void pop_front()
{
    head++;
}
void pop_back()
{
    tail--;
}
int front()
{
    return dat[head];
}
int back()
{
    return dat[tail-1];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /* code */
    return 0;
}