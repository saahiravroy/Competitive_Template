#include<bits/stdc++.h>
using namespace std; 
#define int64_t int  
#define vi vector
#define pb push_back
#define ppb pop_back

const int N=1e5; 
vector<int> v(N); 
vector<int> seg(4*N);
int n;  
void build (int ind ,int low, int high){
	if(low==high){
		seg[ind]=v[low]; 
		return ; 
	}
	int mid=(low+high)>>1; 
	build(2*ind+1, low, mid); 
	build(2*ind+2, low, mid);
	seg[ind]=min(seg[2*ind+1], seg[2*ind+2]);  
}
void update(int ind, int low, int high, int i, int val){

	if(low==high){
		seg[ind]=val; 
		v[i]=val; 
		return ; 
	}

	int mid=(low+high)>>1; 
	if(i<=mid){
		update(2*ind+1, low, mid, i, val); 
	}

	else {

		update(2*ind+2, mid+1, high, i, val); 
	}

	seg[ind]=min(seg[2*ind+1], seg[2*ind+2]); 



}

int range(int ind, int low,int high, int l, int r){

	if(low>=l and high<=r)
		return seg[ind]; 

	if(l>high or low>r )
		return INT_MAX; 

	int mid=(low+high)>>1; 
	int left=range(2*ind+1, low,mid, l, r); 
	int right=range(2*ind+2, mid+1, high, l, r);
	return min (left, right); 
}
int32_t main(){
	
	cin>>n; 
	for(int i=0;i<n;i++){
		cin>>v[i]; 
	}

	build(0, 0, n-1); 
}