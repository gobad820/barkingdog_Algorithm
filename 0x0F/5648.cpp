#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
long long nums[100006];
int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    long long number;
    for (int i = 0; i < n; i++) {
        cin >> number;
        long long rev_num = 0;
        int remainder;
        while (number != 0) {
            remainder = number % 10;
            rev_num = rev_num * 10 + remainder;
            number /= 10;
        }
        nums[i] = rev_num;
    }
    sort(nums, nums + n);
    for (int i = 0; i < n; i++) cout << nums[i] << endl;
    return 0;
}
