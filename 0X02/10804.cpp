#include <bits/stdc++.h>

using namespace std;

/* global variable */
void swap2(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[25];
    for (int i = 1; i <= 20; i++)
        arr[i] = i;

    int a, b;
    for (int i = 0; i < 10; i++)
    {
        cin >> a >> b;
        while (a < b)
        {
            swap2(arr[a], arr[b]);
            a++;
            b--;
        }
    }
    for (int j = 1; j <= 20; j++)
        cout << arr[j] << " ";
    return 0;
}