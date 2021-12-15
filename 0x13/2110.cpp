#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
int n;
std::vector<int> x; // position of house
int c; // the number of router
bool solve(ll target){
  ll distance = -1;
  for(int i = 0 ; i < c ; i++){
    
  }
  return 1;
}
int main(void){
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n >> c;
  for(int i = 0 ; i < n ; i++){
    int tmp;
    std::cin >> tmp;
    x.push_back(tmp);
  }
  std::sort(x.begin(), x.end());
  ll st = 0;
  ll en = 1000000000; 
  while(st < en){
    ll mid = (st + en + 1) /2;
    if(solve(mid)) st = mid;
    else en = mid - 1;
  }
  std::cout << st;
  return 0;
}