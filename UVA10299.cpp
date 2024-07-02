// USER: "Ab.Mahin"
// Problem: Euler Totient Function
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/ETF/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007


template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cout.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 1e5 + 5;
bitset<N> pr;
vector<ll> v;
void siv(){
	v.push_back(2);
	for(ll i = 3; i < N; i += 2){
		if(!pr[i]){
			v.push_back(i);
			for(ll j = i * i; j < N; j += (2 * i)){
				pr[j] = 1;
			}
		}
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
	siv();
    
    ll n;
    while(cin >> n){
    	if(!n) break;
        ll ans = 1;
    	
    	if(n == 1) ans = 0;
    	
    	for(ll i = 0; i < v.size() && v[i] <= n; i++){
    		ll c = 1;
    		while(n % v[i] == 0){
    			n /= v[i];
    			c *= v[i];
    		}
    		if(c != 1){
    			ans = (ans * (c - (c / v[i])));
    		}
    	}
    	if(n > 1){
    		ans = (ans * (n - 1));
    	}
    	
    	
    	cout << ans << '\n';
    }
    
    
    return 0;
}