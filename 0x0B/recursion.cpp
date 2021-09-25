#include <bits/stdc++.h>
using namespace std;
int func(int n) {
  if (n == 1) return n;
  return n + func(n - 1);
}
void func2(int n) {
  if (n == 0)
    return;
  else {
    cout << n << ",";
    return func2(n - 1);
  }
}
int main(int argc, char const* argv[]) {
  /* code */
  int n = 19;
  func2(n);
  cout << "\n";
  cout << func(n);
  return 0;
}
