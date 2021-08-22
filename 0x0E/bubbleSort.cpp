#include<bits/stdc++.h>
using namespace std;
int arr[5] = {2,13,6,4,-2};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 5;
	for(int i = 0 ; i < n-1 ; i++){
		for(int j = 1 ; j < n ; j++){
			if(arr[j] < arr[j-1]) swap(arr[j],arr[j-1]);
		}
	}
	for(int i = 0 ; i < n ; i++) cout << arr[i] << ' ';
	return 0;
}

/*
 *Big-O(N^2)
 * */
