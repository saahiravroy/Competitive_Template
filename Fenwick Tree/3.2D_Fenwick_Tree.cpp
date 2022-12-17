#include<bits/stdc++.h>
using namespace std; 
#define int64_t int  
#define vi vector
#define pb push_back
#define ppb pop_back
const int N=1025; 
int fen[N][N]; 
int n; 
void update(int x, int y, int val){

	while(y<=n){
		fen[x][y]+=val; 
		y+=(y & ~ y); 
	}
}

int sum(int x, int y){
	int sm=0;
	while(y>=1){

		sm+=fen[x][y]; 
		y-=(y &  ~ y); 
	}

	return sm; 
}


int32_t main(){

	int n; cin>>n; 
	int q; cin>>q; 
	while(q--){

		int type; cin>>type; 

		if(type==1){

			//set 
			int x,y,val; cin>>x>>y>>val; 
			update(x, y, val); 
		}

		else if(type==2){

			//sum 

			int x1,x2,y1,y2; cin>>x1>>x2>>y1>>y2; 

			int sm=0; 
			for(int i=x1; i<=x2; i++){

				sm+=sum(i, y2)-sum(i, y1-1); 
			}

			cout<<sm<<endl; 
		}
	}
	
}