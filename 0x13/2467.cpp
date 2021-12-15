#include <algorithm>
#include <cmath>
#include <iostream>
int n;
int solutions[100005];
int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n;
  std::cout << n;
  // for (int i = 0; i < n; i++) std::cin >> solutions[i];
  // int abslt = 2000000000;
  // std::pair<int, int> pos;  // binary search같은 이분 탐색으로
  // for (int i = 0; i < n; i++) {
  // }
  // // 고안해낸 방법은 O(N^2)
  // // 어떻게 해야 O(NlgN)이나 O(N)으로 변경 가능한가

  // std::cout << solutions[pos.first] << " " << solutions[pos.second];
  return 0;
}