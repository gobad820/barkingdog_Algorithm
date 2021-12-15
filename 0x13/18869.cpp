#include <algorithm>
#include <iostream>
#include <vector>
int n, m;
std::vector<int> universe[10005];
int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int tmp;
      std::cin >> tmp;
      universe[i].push_back(tmp);
    }
  }
  
  return 0;
}