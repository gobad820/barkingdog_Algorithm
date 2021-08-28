#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
long long mxval;
int mxcnt;
long long nums[100006];

int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums, nums + n);
    nums[n] = (1ll << 62) + 1; // 1ll long long type 크기 left shift 
    cnt = 1;
    mxval = -(1ll << 62) - 1;
    mxcnt = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i - 1] == nums[i])
            cnt++;
        else {  // 다른 수 등장
            if (cnt > mxcnt) {
                mxval = nums[i - 1];
                mxcnt = cnt;
            }
            cnt = 1;
        }
    }
    cout << mxval;
    return 0;
}

// 개선방향
// 1. nums[n]에 2^62+1값을  넣고 for n-1까지가 아니라 n까지 돌면 27삭제 가능
// 2.cnt에 0을 넣는게 아니라 1을 넣고 시작하면 i를 0이 아닌 1부터 시작 가능
// ->따라서 i==0과 같은 예외 처리가 필요 없어 진다.
