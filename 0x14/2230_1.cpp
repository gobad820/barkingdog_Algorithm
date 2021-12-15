#include <algorithm>
#include <iostream>
int n, m;
int a[100005];
int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  std::sort(a, a + n);
  int en = 0;
  int ans = int(2e9);
  for (int st = 0; st < n; st++) {
    while (en < n && a[en] - a[st] < m) en++;
    if (en == n) break;
    ans = std::min(ans, a[en] - a[st]);
  }
  std::cout << ans;
  return 0;
}