#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
ll a, b, c;
void p(int g) {}
ll POW(ll a, ll b, ll m) {
    if (b == 1) return a % m;  // base cƒondition
    ll val = POW(a, b / 2, m);
    val = val * val % m;
    if (b % 2 == 0)
        return val;
    else
        return val * a % m;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    cout << POW(a, b, c);
    return 0;
}
