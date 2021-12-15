#include <algorithm>
#include <iostream>
#include <vector>
std::vector<int> arr;
int n;
int x[1000005];
int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> x[i];
    arr.push_back(x[i]);
  }
  std::sort(arr.begin(), arr.end());
  for (std::vector<int>::iterator it = arr.begin(); it < arr.end(); it++) {
    if (*it == *(it - 1) && it != arr.begin()) arr.erase(it);
  }
  for (int i = 0; i < n; i++)
    std::cout << std::lower_bound(arr.begin(), arr.end(), x[i]) - arr.begin()
              << " ";
  return 0;
}
