#include <bits/stdc++.h>
/* header */
using namespace std;
#define endl "\n"
const int MX = 1000005;
int dat[MX];
int front = 0, rear = 0;

void push(int x)
{
    dat[rear++] = x;
}
void pop()
{
    front++;
}
int front_print()
{
    return dat[front];
}
int rear_print()
{
    return dat[rear - 1];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /* code */
    return 0;
}