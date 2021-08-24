#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
int arr[100005][2];
int tmp[100005][2];

void merge(int st, int en){
	int mid = (st+en)/2;
	int lidx = st; int ridx = mid;
	for(int i = st; i < en ; i++){
		// x 좌표 우선 비교 후 y 좌표 비교
		if( lidx == mid) {
			tmp[i][0] = arr[ridx][0];
			tmp[i][1] = arr[ridx++][1];
		}
		else if(ridx == en){
			tmp[i][0] = arr[lidx][0];
			tmp[i][1] = arr[lidx++][1];
		}
		else if(arr[lidx][0] == arr[ridx][0]){
			if(arr[lidx][1] <= arr[ridx][1]){
				tmp[i][0] = arr[lidx][0];
				tmp[i][1] = arr[lidx++][1];
			}
			else{
				tmp[i][0] = arr[ridx][0];
				tmp[i][1] = arr[ridx++][1];
			}
		}
		else if(arr[lidx][0] < arr[ridx][0]){
			tmp[i][0] = arr[lidx][0];
			tmp[i][1] = arr[lidx++][1];
		}
		else{
			tmp[i][0] = arr[ridx][0];
			tmp[i][1] = arr[ridx++][1];
		}
	}
	for(int i = st ; i < en ; i++){
		arr[i][0] = tmp[i][0];
		arr[i][1] = tmp[i][1];
	}
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
	int a,b;
	for(int i = 0 ; i < n ; i++) cin >> arr[i][0] >> arr[i][1];
	mergeSort(0,n);
	for(int i = 0 ; i < n ; i++) cout << arr[i][0] << ' ' << arr[i][1] << endl;
	return 0;
}

