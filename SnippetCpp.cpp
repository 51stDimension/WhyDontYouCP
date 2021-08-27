/**
* @Author:51D
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//Variant Technique Usage like 10101010 and 01010101
//The value of str[i]^(i%2) is 1 for the first string and 0 for the second //string
//Also sometimes try to think Binary
//Sometimes think about array by denoting its elements in bar graph form
//Break into smaller test cases such as n=2 n=3 and n=4
//In transformation type questions focus on the endcase and also see if //its unique
//First approach when n is small is do brute forces. Optimize after contest
//set has duplicate elements issues(prefer multiset)
//If multiple times sorting required use multiset
//Sometimes think string traversal from back


//See this during Debug Sessions
//if(curr>=s.length() || curr<0 || visited[curr])
//Always use the variable as a index after checking bounds

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define mod 1000000007
#define inf 1e9
#define f(i,n) for(int i=0;i<n;i++)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t) ll tt;cin>>tt;while(tt--)
#define pb push_back
#define endl "\n"
#define read(arr,n) for(ll i=0;i<n;i++){cin>>arr[i];};
#define pi pair<ll,ll>
#define all(arr) arr.begin(),arr.end()

template <typename T>
using ordered_set = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

const int N=2e5+5;
const long long infll = 0x3f3f3f3f3f3f3f3fLL;
int p[N];

ll modulo(int a, int b, int n){
    ll x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
            
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}

ll value[1000001];
void fillNumberOfDivisorsArray(){
    for(ll i=1;i<=1000000;i++){
        for(ll j=1;i*j<=1000000;j++){
            value[i*j]++;
        }
    }
}

bool SeiveArray[40000];

vector<ll> PrimeNumArray;

void seiveFill(){
    memset(SeiveArray,true,sizeof(SeiveArray));

    SeiveArray[0] = SeiveArray[1] = false;

    for(ll i=2;i<40000;i++){
        if(SeiveArray[i]) PrimeNumArray.pb(i);
        
        for(ll j=i*2;j<40000;j+=i){
            SeiveArray[j] = false;
        }
    }
}

ll PrimeF(ll num){
    ll count = 0;
    
    for(auto n:PrimeNumArray){
        while(num%n==0){
            num = num/n;
            count++;
        }
    }
    if(num>1) count++;

    return count;
}

void addEdge(vector<ll> adj[],ll u,ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

ll __lcm(ll a,ll b){
    return a*b/(__gcd(a,b));
}

vector<ll> fact;
void factorialFill(){
    fact.pb(1);
    fact.pb(1);
    for(ll i=2;i<=1000000;i++){
        fact.pb((i%mod * fact.back()%mod)%mod);
    }
}
ll getfact(ll num){
    return fact[num]%mod;
}

struct cmp {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.first < b.first;
    }
};
//Use the above comparator when you want custom set sorting

/*

Start thinking,writing,just do something
Testcases likhte reh figure out hojayega
If its too tough kuch toh pattern hoga
Ask questions to yourself
Take baby steps with the question and then merge ur ideas
Just Remember that the question has something hidden. (It is solvable)
You dont want to regret after reading the editorial.
Miro board mein shuroo hoja bas.
During pair type questions:
Maybe there is no need to check all pairs. Try proving that
HashMap
Seive
All the best!


Kisiko Ghanta Farak padta hai tere rating se.
Solve kar. No matter how many times you have to submit. 
If counfused with a conclusion try proving with n=2 and n=3

Try Thinking Brute Force alongwith PigeonHole(Hard to observe)
Whenever you get a constructive problem. Try solving for n=2,n=3,n=4 and then start generalizing till n=6
*/
void solve(ll tc){
        
}

int main() {

    FIO;
    //seiveFill();
    //factorialFill();
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    ll tt;
    cin>>tt;
    for(ll i=1;i<=tt;i++){
        solve(i);
    }

    return 0;
}
