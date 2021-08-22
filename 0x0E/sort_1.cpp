#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
/* global variable */

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[10] = {3, 2, 7, 235, 73, 839, 444, 34728, 2, 51};
    int n = 10;
    for (int i = n - 1; i >= 0; i--) {
        int max = 0;
        for (int j = 0; j <= i; j++) {
            if (arr[max] < arr[j]) max = j;
        }
        swap(arr[max], arr[i]);
    }
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';

    for (int i = n - 1; i > 0; i--) {
        swap(*max_element(arr, arr + i + 1), arr[i]);
    }
    return 0;
}