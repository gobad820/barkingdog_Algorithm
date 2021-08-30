#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
string s;
string tail[1005];
int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	for(int i = 0 ; i < s.length() ; i++){
		for(auto j : s) tail[i] += j;
		tail[i].erase(0,i);
	}
	sort(tail,tail+s.length());
	for(int i = 0 ; i < s.length() ; i++) cout << tail[i] << endl;
	return 0;
}

