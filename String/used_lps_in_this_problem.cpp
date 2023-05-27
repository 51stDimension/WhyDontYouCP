/**
* @Author:your.nemesis
**/

#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <climits>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <sstream>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

#define mod 1000000007
#define inf 1e9
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t) ll tt;cin>>tt;while(tt--)
#define pb push_back
#define endl "\n"
#define all(arr) arr.begin(),arr.end()


// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//options: less,greater_equal,less_equal,greater

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int N=3e5+5;
const long long infll = 0x3f3f3f3f3f3f3f3fLL;
int p[N];

vector<ll> computeLPS(vector<ll> pat){
    ll n = pat.size();

    vector<ll> lps(n);

    lps[0] = 0;

    ll i = 1;
    ll len = 0;

    while(i<n){
        if(pat[len] == pat[i]){
            lps[i] = len+1;
            len++;
            i++;  
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len - 1];
            }
        }
    }

    return lps;
}

void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<ll> a(n),b(m);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    for(ll i=0;i<m;i++){
        cin>>b[i];
    }

    if(m==1){
        cout<<n<<endl;
        return;
    }

    if(n==1){
        cout<<0<<endl;
        return;
    }

    vector<ll> text;
    vector<ll> pat;

    for(ll i=1;i<n;i++){
        text.pb(a[i] - a[i-1]);
    }
    for(ll i=1;i<m;i++){
        pat.pb(b[i] - b[i-1]);
    }

    debug(text,pat);

    vector<ll> lps = computeLPS(pat);

    ll i = 0;
    ll j = 0;

    ll cnt = 0;

    while(i<text.size()){   

        if(text[i] == pat[j]){
            i++;
            j++;
        }

        if(j==pat.size()){
            cnt++;
            j = lps[j-1];
        }

        if(i<text.size() && text[i]!=pat[j]){
            if(j==0){
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }

    cout<<cnt<<endl;       
}

int main() {

    FIO;
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    ll tt = 1;
    for(ll i=1;i<=tt;i++){
        solve(i);
    }

    return 0;
}
