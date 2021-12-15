#include <algorithm>
#include <iostream>
int n, m;
int a[100005];
int s[100005];
int ans = 100005;
bool solve(int st) {
  int head = st;
  int tail = n - 1;
  while (head < tail) {
    int mid = (tail + head) / 2;
    if (s[mid] == m) head = tail;
  }
  return true;
}
int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  s[0] = a[0];
  for (int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];
  for (int st = 1; st < n; st++) {
    int en = solve(st);
    if (en != n) ans = std::min(ans, en - st + 1);
  }
  return 0;
}