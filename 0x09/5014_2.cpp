#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int F, S, G, U, D;
int vis[1000007];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> F >> S >> G >> U >> D;
    if (S < G && U == 0)
        cout << "use the stairs" << endl;
    if (S > G && D == 0)
        cout << "use the stairs" << endl;
    

    return 0;
}