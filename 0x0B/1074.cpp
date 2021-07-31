#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int Z(int r, int c, int n) {  // n * n 배열에서 [r][c]의 방문 순서
    if (n == 0) return 0;     // base condition
    int half = 1 << (n - 1); // 비트 이동 2^n-1을 나타냄
    // 1번 사각형
    if (r < half && c < half) return Z(r, c, n - 1);
    // 2번 사각형
    else if (r < half && c >= half)
        return half * half + Z(r, c - half, n - 1);
    // 3번 사각형
    else if (r >= half && c < half)
        return 2 * half * half + Z(r - half, c, n - 1);
    // 4번 사각형
    return 3 * half * half + Z(r - half, c - half, n - 1);
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r, c;
    cin >> n >> r >> c;
    cout << Z(r, c, n);
    return 0;
}
/*
 * 직접 배열을 만들어서 방문을 할 생각만 함
 * 엄청난 패인이 되어버림
 * 굳이 방문하지 않아도 되었음
 * 그냥 순서만 잘 생각하는 문제.
 * 정사각형의 구조를 유지하고 있기 때문
 */