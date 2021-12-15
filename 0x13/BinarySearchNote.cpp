#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int a[590000];
int func(int target, int len){
	int st = -1;
	int en = len-1;
	while(st < en){
		int mid = (st+en)/2;
		if(a[mid] >= target) en = mid -1;
		else st = mid;
	}
	return st;
}
/*
 * mid값이 항상 2인 경우 발생
 * 무한 루프 발생
 *
 *
 * */
int main(int argc, char const *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	return 0;
}

