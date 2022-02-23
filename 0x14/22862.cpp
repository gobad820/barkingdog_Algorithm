#include <algorithm>
#include <iostream>
#include <vector>
int n, k;
int a[1000005];
int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n >> k;
  int tmp;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  int en = 0;
  int ans = -1;
  int odd = 0;
  for (int st = 0; st < n; st++) {
    while (en < n && odd < k)
      if (a[en++] % 2 != 0) odd++;
    if (en == n) break;
    ans = std::max(ans, en - st - k);
    if (a[st] % 2 != 0) odd--;
  }
  std::cout << ans;
  return 0;
}