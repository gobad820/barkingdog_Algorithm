#include <algorithm>
#include <iostream>
#include <vector>
int n, m;
std::vector<long long> a;
bool solve(long long tmp) {
  for (int i = 0; i < n; i++) {
    if (std::binary_search(a.begin(), a.end(), tmp + a[i])) return true;
  }
  return false;
}
int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int tmp;
    std::cin >> tmp;
    a.push_back(tmp);
  }
  std::sort(a.begin(), a.end());
  long long result = 2000000000;
  std::cout << *(std::upper_bound(a.begin(), a.end(), 1 + 3));
  for (int i = 0; i < n; i++) {
    long long tmp = *(std::lower_bound(a.begin(), a.end(), a[i] + m)) - a[i];
    if (tmp < m) continue;
    result = std::min(result, tmp);
  }
  std::cout << result;
  return 0;
}

// 오답인 이유
// for (int i = 0; i < n; i++) {
//   long long tmp = *(std::lower_bound(a.begin(), a.end(), a[i] + m)) - a[i];
//   std::cout << tmp;
//   return 0;
// }
// tmp가 m보다 조금 큰 값을 처음에 리턴할 수 있기 때문
// 예를 들어 1 5는 m보다 큰 4를 return 하지만
// 2 5가 존재할 수 있기 때문 2 5는 3을 return하므로 더 적합하다.