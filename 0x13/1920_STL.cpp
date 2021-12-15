#include <algorithm>
#include <iostream>
int n;
int a[100005];
int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  std::sort(a, a + n);
  int m;
  std::cin >> m;
  for (int i = 0; i < m; i++) {
    int tmp;
    std::cin >> tmp;
    std::cout << std::binary_search(a, a + n, tmp) << "\n";
  }
  return 0;
}