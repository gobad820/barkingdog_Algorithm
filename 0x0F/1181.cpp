#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
string words[20005];
bool cmp(const string &a, const string &b) {
    if (a.length() < b.length())
        return true;
    else if (a.length() == b.length())
        return a < b;
    else
        return false;
}
int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> words[i];
    sort(words, words + n, cmp);
    for (int i = 0; i < n; i++) {
        if (words[i] == words[i - 1]) continue;
        cout << words[i] << endl;
    }
    return 0;
}
