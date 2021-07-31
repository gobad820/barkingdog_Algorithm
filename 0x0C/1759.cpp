#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int l, c;
char arr[20];
char password[20];
bool isused[20];
void func(int cur) {
    if (cur == l) {
        int a = 0;
        int b = 0;
        for (int i = 0; i < l; i++) {
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' ||
                arr[i] == 'o' || arr[i] == 'u')
                a++;
            else
                b++;
        }
        if (a >= 1 && b >= 2) {
            for (int i = 0; i < l; i++) cout << arr[i];
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < c; i++) {
        if (isused[i]) continue;
        if (cur > 0 && arr[cur - 1] > password[i]) continue;
        arr[cur] = password[i];
        isused[i] = 1;
        func(cur + 1);
        isused[i] = 0;
    }
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> c;
    for (int i = 0; i < c; i++) cin >> password[i];
    sort(password, password + c);
    func(0);
    return 0;
}