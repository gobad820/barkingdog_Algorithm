#include <algorithm>
#include <iostream>
#include <vector>
int n;
int x[1000005];
std::vector<int> arr;
int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> x[i];
    arr.push_back(x[i]);
  }
  std::sort(arr.begin(), arr.end());
  arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
  for (int i = 0; i < n; i++) {
    std::cout << std::lower_bound(arr.begin(), arr.end(), x[i]) - arr.begin()
              << " ";
  }
  return 0;
}