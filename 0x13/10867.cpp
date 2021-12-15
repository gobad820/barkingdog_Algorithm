#include <algorithm>
#include <iostream>
#include <vector>
int n;
std::vector<int> arr;
int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int target;
    std::cin >> target;
    arr.push_back(target);
  }
  std::sort(arr.begin(), arr.end());
  arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
  for (std::vector<int>::iterator it = arr.begin(); it < arr.end(); it++)
    std::cout << *it << " ";
  return 0;
}