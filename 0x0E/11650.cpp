#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef struct{
	int x;
	int y;
}dots;

vector<dots> v(100005);
dots tmp[100005];
int n;

void merge(int st, int en){
	int mid = (st+en)/2;
	int lidx = st; int ridx = mid;
	for(int i = st ; i < en ; i++){
		if(lidx == mid){
			tmp[i].x = v[ridx].x;
			tmp[i].y = v[ridx++].y;
		}
		else if(ridx == en){
			tmp[i].x = v[lidx].x;
			tmp[i].y = v[lidx++].y;
		}
		else if(v[lidx].x == v[ridx].x){
			if(v[lidx].y <= v[ridx].y){
				tmp[i].x = v[lidx].x;
				tmp[i].y = v[lidx++].y;
			}
			else{
				tmp[i].x = v[ridx].x;
				tmp[i].y = v[ridx++].y;
			}
		}
		else if(v[lidx].x < v[ridx].x){
			tmp[i].x = v[lidx].x;
			tmp[i].y = v[lidx++].y;
		}
		else{
			tmp[i].x = v[ridx].x;
			tmp[i].y = v[ridx++].y;
		}
	}
	for(int i = st ; i < en ; i++){
		v[i].x = tmp[i].x;
		v[i].y = tmp[i].y;
	}
}
void mergeSort(int st, int en){
	if(st + 1 == en) return;
	int mid = (st+en)/2;
	mergeSort(st,mid);
	mergeSort(mid,en);
	merge(st,en);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> v[i].x >> v[i].y;
	mergeSort(0,n);
	for(int i = 0; i < n; i++) cout << v[i].x << ' ' << v[i].y << endl;
	return 0;
}