#include <bits/stdc++.h>
using namespace std;
int arr[1005];
int tmp[1005];
int n;

void quickSort(int st, int en){
	if(en <= st+1) return; // 배열의 크기가 1이면 종결 // base condition
	int pivot = arr[st];
	int l = st+1;
	int r = en-1;
	while(1){
		while(l <= r && arr[l] <= pivot) l++;
		while(l <= r && arr[r] >= pivot) r--;
		if(l > r) break;
		swap(arr[l],arr[r]);
	}
	swap(arr[st],arr[r]);
	quickSort(st,r);
	quickSort(r+1,en);
}

void merge(int st, int en){
	int mid = (st+en)/2;
	int lidx = st; int ridx = mid;
	for(int i = st ; i < en ; i++){
		if(lidx == mid) tmp[i] = arr[ridx++];
		else if(ridx == en) tmp[i] = arr[lidx++];
		else if(arr[lidx] >= arr[ridx]) tmp[i] = arr[ridx++];
		else tmp[i] = arr[lidx++];
	}
	for(int i = st ; i < en ; i++) arr[i] = tmp[i];
}
void mergeSort(int st, int en){
	if(st+1 == en) return;
	int mid = (st+en)/2;
	mergeSort(st,mid);
	mergeSort(mid,en);
	merge(st,en);
}
int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> arr[i];
	//quickSort(0,n);
	mergeSort(0,n);
	for(int i = 0 ; i < n ; i++) cout << arr[i] << ' ';
	return 0;
}
	
