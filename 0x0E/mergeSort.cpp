#include <bits/stdc++.h>
using namespace std;
int n = 5;
int arr[5] = {5,4,3,2,1};

void merge(int arr[],int l, int m, int r){
	int tmp[n];
}
void mergeSort(int arr[], int l, int r){
	if(l > r) // 한 칸이 남을 때 가지 분할
		return;
	int middle = (r+l)/2;
	mergeSort(int arr[],l,middle);
	mergeSort(int arr[],middle+1,r);
	merge(int arr[],l,middle,r);
}

int main(int argc, const char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	return 0;
}

