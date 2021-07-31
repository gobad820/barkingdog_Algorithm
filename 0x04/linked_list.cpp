#include <bits/stdc++.h>
/* header */
using namespace std;
#define endl "\n"

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num)
{
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1) // 마지막 원소가 아니라면
        pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr)
{
    //if there is no element in this list
    if (unused == 1)
        return;
    dat[addr] = -1;
    // if there is one element
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = pre[pre[addr]];
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);

    return 0;
}