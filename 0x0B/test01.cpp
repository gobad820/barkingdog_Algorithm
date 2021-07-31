#include <bits/stdc++.h>
/* header */
using namespace std;
#define endl "\n"
/* global variable */
using ll = long long;

ll func1(ll a, ll b, ll m) {
    ll val = 1;
    while (b--) {
        val = val * a % m;
    }
    return val;
}
ll func2(ll a, ll b, ll m) {
    ll val = 1;
    val = a % m;
    ll k = 1;
    ll i = 0;
    while (b > 2 * k) {
        k *= 2;
        i++;
    }
    val = pow(a, k);
    cout << val;
    ll c = b % 2;
    while (c--) {
        val = val * a % m;
    }
    return val;
}

ll POW(ll a, ll b, ll m) {
    if (b == 1) return a % m;
    ll val = POW(a, b / 2, m);
    val = val * val % m;
    if (b % 2 == 0) return val;
    return val * a % m;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /* code */
    ll a, b, m;
    cin >> a >> b >> m;
    ll result = func2(a, b, m);
    cout << result;
    return 0;
}