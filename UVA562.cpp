// USER: "Ab.Mahin"
// Problem: 562 - Dividing coins
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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
const ll N = 2e5 + 5;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
    
    cin >> t;
	
    while(t--){
        ll n;
        cin >> n;
        
        ll a[n], sum = 0, ans = 0, res = 0;
        
        for(ll i = 0; i < n; i++) cin >> a[i], sum += a[i];
        ans = sum;
        sum /= 2;
        ll dp[sum + 1]{0};
        dp[0] = 1;
        for(ll i = 0; i < n; i++){
        	for(ll j = sum; j >= a[i]; j--){
        		dp[j] |= dp[j - a[i]];
        	}
        }
        
        for(ll i = 0; i <= sum; i++){
        	if(dp[i]){
        		res = i;
        	}	
        }
        cout << abs(ans - (2 * res)) << '\n';
        
    }
    
    
    return 0;
}