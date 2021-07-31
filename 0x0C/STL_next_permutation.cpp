#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 3;
    int arr[3] = {3, 5, 7};
    do {
        cout << arr[0] << " " << arr[1] << " " << arr[2];
        cout << endl;
    } while (next_permutation(arr, arr + n));
    return 0;
}