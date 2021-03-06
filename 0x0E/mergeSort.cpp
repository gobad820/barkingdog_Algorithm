#include <bits/stdc++.h>
using namespace std;
int n = 10;
int arr[1000001];
int tmp[1000001];

void merge(int st, int en){
	int mid = (st+en)/2;
	int lidx = st;
	int ridx = en;
	for(int i = st; i < en ; i++){
		if(lidx == mid) tmp[i] = arr[ridx++];
		else if(ridx == en) tmp[i] = arr[lidx++];
		else if(arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
		else tmp[i] = arr[ridx++];
	}
	for(int i = st; i < en; i++) arr[i] = tmp[i];
}
void mergeSort(int st, int en){
	if(en == st+1) // 한 칸이 남을 때 가지 분할
		return;
	int middle = (st+en)/2;
	mergeSort(st,middle);
	mergeSort(middle,en);
	merge(st,en);
}

int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	mergeSort(0,n);
	for(int i = 0; i < n ; i++) cout << arr[i] << ' ';
	return 0;
}

