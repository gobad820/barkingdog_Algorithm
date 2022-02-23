#include <iostream>
int n, m;
int a[10005];
int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  int en = 0;
  int tmp = 0;
  int ans = 0;
  for (int st = 0; st < n; st++) {
    while (en < n && tmp < m) tmp += a[en++];
    if (n == en) break;
    if (tmp == m) ans++;
    tmp -= a[st];
  }
  std::cout << ans;
  return 0;
}