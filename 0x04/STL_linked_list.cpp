#include <bits/stdc++.h>
/* header */
using namespace std;
#define endl "\n"
/* global variable */

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    list<int> L = {1, 2};
    list<int>::iterator t = L.begin();
    // t는 1을 가르키고 있음
    L.push_front(10);
    // { 10, 1, 2} t는 여전히 1을 가르키고 있다
    cout << *t << endl;
    // 1 출력
    for (auto i : L)
        cout << i << " ";
    cout << endl;
    L.push_back(5);
    // {10, 1, 2, 5}
    L.insert(t, 7);
    // {10, 7, 1, 2, 5}
    t++;
    // t는 2를 가리킴
    t = L.erase(t);
    // 2 제거

    cout << *t << endl;
    // 그리고 5를 가리킴
    for (auto i : L)
        cout << i << " ";
    cout << endl;
    for (list<int>::iterator it = L.begin(); it != L.end(); it++)
        cout << *it << " ";

    return 0;
}