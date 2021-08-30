#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define X first
#define Y second
int n;
vector<pair<int, string> > mem;
bool cmp(pair<int, string> a, pair<int, string> b) {  // pair만 사용해도 가능함
    return a.X < b.X;                                 // 비교 함수
}
int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int age;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> age >> name;
        mem.push_back({age, name});
    }
    stable_sort(mem.begin(), mem.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << mem[i].X << ' ' << mem[i].Y << endl;
    }
    return 0;
}
