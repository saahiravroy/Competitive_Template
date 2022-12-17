#include<bits/stdc++.h>
using namespace std;
#define int64_t int
#define vi vector
#define pb push_back
#define ppb pop_back


void cordinate_compression(int a[], int n) {

	set<int> st ;
	map<int, int> mp;
	for (int i = 1; i <= n; i++)st.insert(a[i]);

	int cnt = 1;
	for (auto it : st) {

		mp[it] = cnt++;
	}

	for (int i = 1; i <= n; i++)a[i] = mp[a[i]];
}
int32_t main() {


}