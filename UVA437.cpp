// Problem: D. Connect the Dots
// Contest: Codeforces - Codeforces Round 976 (Div. 2) and Divide By Zero 9.0
// URL: https://codeforces.com/contest/2020/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007 // 998244353
// 0x3f
 
#define MAX LLONG_MAX
 
template <class T>
using ordered_set =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// find_by_order() and order_of_key()
// k-th largest element and strictly smaller
 
// Findout buggs:
 
#define BUG
 
#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define bug(...)
#endif
 
//...................
const ll N = 1e7 + 5;
ll n;
ll dp[200];

vector<tuple<ll ,ll, ll>> v;

ll solve(ll i){
	if(i == n) return 0;
	ll &res = dp[i];
	if(~res) return res;
	res = 0;
	auto [x, y, z] = v[i];
	for(ll j = 0; j < n; j++){
		auto [l, w, h] = v[j];
		if(l < x && w < y){
		  //  bug(l, w, h);
			res = max(res, solve(j) + h);
		}
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/
 	
 	ll tt = 1;
 	
 	while(cin >> n && n){
 		v.clear();
 		v.push_back({MAX, MAX, 0});
 		for(ll i = 0; i < n; i++){
 			ll x, y, z;
 			cin >> x >> y >> z;
 			v.push_back({x, y, z});
 			v.push_back({y, x, z});
 			v.push_back({z, x, y});
 			
 			v.push_back({y, z, x});
 			v.push_back({x, z, y});
 			v.push_back({z, y, x});
 		}
 		n = v.size();
 		memset(dp, -1, sizeof dp);
 		cout << "Case " << tt++ << ": maximum height = " << solve(0) << '\n';
 	}
 
    return 0;
}
