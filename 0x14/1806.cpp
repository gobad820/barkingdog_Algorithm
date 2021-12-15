#include <algorithm>
#include <iostream>
int n, s;
int a[100005];
long long tmp = 0;
int ans = 100005;
int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n >> s;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  int en = 0;
  for (int st = 0; st < n; st++) {
    while (en < n && tmp < s) tmp += a[en++];
    if (en == n && tmp < s) break;
    ans = std::min(en - st, ans);
    tmp -= a[st];
  }
  if (ans == 100005)
    std::cout << 0;
  else
    std::cout << ans;
  return 0;
}
