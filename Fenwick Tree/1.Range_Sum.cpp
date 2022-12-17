#include<bits/stdc++.h>
using namespace std; 
#define int64_t int  
#define vi vector
#define pb push_back
#define ppb pop_back
const int N=1e5+1; 
int fen[N]; 
int n;

void update(int ind, int val){

	while(ind<=n){
		fen[ind]+=val; 
		ind=ind+(ind & ~ind); 
	}
} 

int sum(int ind){

	int s=0; 
	while(ind>=1){
		s+=fen[ind]; 
		ind-=(ind & ~ ind); 
	}

	return s; 
}

void queries(){

	int n,q; cin>>n>>q; 
	int a[n+1]; 
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		update(i, a[i]); 
	}

	while(q--){

		int type; cin>>type; 
		if(type==1){
			int ind,val;  
			cin>>ind>>val; 
			update(ind, val); 
		}
		else {

			int l,r; cin>>l>>r; 
			cout<<sum(r)-sum(l-1)<<endl; 
		}
	}
}
int32_t main(){
	
	
}