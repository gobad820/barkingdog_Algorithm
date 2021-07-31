#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

void reverse(deque<int>& dq){

	deque<int> dq2;
	for(int i = 1 ; i <= 10 ; i++){
		dq2.push_back(dq.back());
		dq.pop_back();
	}

	for(int i = 1 ; i <= 10 ;i++){
		dq.push_back(dq2.front());
		dq2.pop_front();
	}

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	deque<int> dq;

	for(int i = 1 ; i <= 10 ; i++)
		dq.push_back(i);
	
	reverse(dq);
	for(int i = 0 ; i < 10 ; i++){
		cout << dq.front() << " ";
		dq.pop_front();
	}
	return 0;
}
