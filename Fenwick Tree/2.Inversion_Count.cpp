#include<bits/stdc++.h>
using namespace std; 
#define int64_t int  
#define vi vector
#define pb push_back
#define ppb pop_back

const int N=1e5+1; 
int fen[N]; 
int freq[N]; 
int n;
void update(int ind,int val){

	while(ind<=n){
		fen[ind]+=val; 
		ind+=(ind & ~ ind); 
	}
}
int sum(int ind){

	int s=0; 
	while(ind>=1){
		s+=fen[ind]; 
		ind-=(ind &  ~ind ); 
	}

	return s; 
}

void invCount(){

	int n;cin>>n; 
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		freq[a[i]]++; 
		update(a[i], 1); 
	}
	int count=0; 
	for(int i=1;i<=n;i++){
		freq[a[i]]--; 
		update(a[i], -1); 
		count+=sum(a[i]-1); 
	}

	cout<<count<<endl; 
}
int32_t main(){
	
	
}