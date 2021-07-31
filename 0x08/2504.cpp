#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a;
	getline(cin, a);
	
	int result = 1;
	stack<int> s;
	bool isValid = true;
	bool start = true;
	int p_s = 0;
	int pu = 0;
	for(auto c : a){
		if(c == '(' || c == '[') {
			if(c == '(') s.push(2);
			else s.push(3);
			p_s--;
			pu++;
		}
		else if(c == ')'){
			if(s.empty() || s.top() != 2){
				isValid = false;
				break;
			}
			
			if(start || p_s != 0) result *= s.top();
			else result += s.top();
			s.pop();
			start = false;
			p_s++;pu--;
		} 
		else if(c == ']'){
			if(s.empty() || s.top() != 3){
				isValid = false;
				break;
			}
			if(start || p_s != 0) result *= s.top();
			else result += s.top();
			s.pop();
			start = false;
			p_s++;pu--;
		}
	}

	if(!s.empty()) isValid = false;
	if(isValid) cout << result << "\n";
	else cout << 0 << "\n";

	return 0;

}
