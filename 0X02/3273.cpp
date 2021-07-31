#include <bits/stdc++.h>
/* header */
using namespace std;
#define endl "\n"
int n;
int arr[100005];
int m;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> m;
    sort(arr, arr + n);
    int result = 0;
    int arr2[arr[n] + 5];
    for (int i = 0; i < n; i++)
    {
        arr2[arr[i]]++;
        if (arr2[m - arr[i]] > 0)
            result++;
    }
    cout << result;
    return 0;
}