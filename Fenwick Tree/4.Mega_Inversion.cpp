#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int int64_t
#define pi 3.141592653589793238462
#define mod 1000000007
#define oo 1e18
#define inf 2e9
#define null NULL
#define up upper_bound
#define lb lower_bound
#define ff first
#define ss second
#define vi vector<int>
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,x,y) for(int i=x;i<=y;i++)
#define rev(i,x,y) for(int i=x;i>=y;i--)
#define set_bits __builtin_popcountll
#define pb push_back
#define ppb pop_back
#define tcc int t;cin>>t;while(t--)
typedef unsigned long long ull;
typedef long double lld;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds;

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
	if (start < 0) start = 0;
	if (end < 0) end = int(v.size());

	for (int i = start; i < end; i++)
		cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
	//use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

int ceil (int n, int k) {return (n + k - 1) / k;  }
int power (int a, int b, int m = int(2e18)) { if (b == 0) return 1; if (b == 1)	return a; if (b % 2 == 1)	return (power(a, b - 1) * a) % m; int q = power(a, b / 2); return (q * q) % m; }
int gcd (int a, int b ) { if (b == 0) {  return a; } else  { return gcd( b, a % b ); } }
int lcm (int a, int b) { return (a * b) / gcd(a, b); }

//a^p = a (mod p) p is prime // a^-1 = a^(p-2) (mod p )
//find_by_order(i) -> Element at ith idx [0 based index]
//order_of_key(x)  -> NO of Element strictly Lesser Than x
//THINK MORE CODE LESS !
const int N = 1e5 + 1;
int fenRight[N];
int fenLeft[N];
int freqRight[N];
int freqLeft[N];
int n;
void update1(int ind, int val) {

	while (ind <= n) {
		fenRight[ind] += val;
		ind += (ind &  -ind);
	}
}
int sum1(int ind) {

	int s = 0;
	while (ind >= 1) {
		s += fenRight[ind];
		ind -= (ind &  -ind );
	}

	return s;
}

void update2(int ind, int val) {

	while (ind <= n) {
		fenLeft[ind] += val;
		ind += (ind &  -ind);
	}
}
int sum2(int ind) {

	int s = 0;
	while (ind >= 1) {
		s += fenLeft[ind];
		ind -= (ind &  -ind );
	}

	return s;
}


void solve()
{
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {

		freqRight[a[i]]++;
		update1(a[i], -1);
		int c1 = sum1(a[i] + 1);
		int c2 = sum2(n) - sum2(a[i]);

		cnt += c1 * c2;

		freqLeft[a[i]]++;
		update2(a[i], 1);
	}

	cout << cnt << endl;
}
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	solve();
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}