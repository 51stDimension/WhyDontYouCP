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


struct cmp {
    bool operator() (const pair<ll, ll> &a, const pair<ll, ll> &b) const {
        return a.first >= b.first;
    }
};

//Coding Blocks DP course question under One Dimensional DP section

void solve(ll tc){
    ll n,k;
    cin>>n>>k;

    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }      

    vector<ll> dp(n);

    dp[0] = arr[0];

    set<pair<ll,ll>,cmp> s;

    for(ll i=1;i<k;i++){

        dp[i] = dp[i-1];
        dp[i] = max(dp[i],arr[i]);

        s.insert({dp[i],i});
    }

    ll ime = -1,mf1 = -1,mf2 = -1;

    for(ll i=k;i<n;i++){

        if(i%k == 0){

            ime = (*s.begin()).second;
            mf1 = (*s.begin()).first;
            s.erase(s.begin());
            mf2 = (*s.begin()).first;


            s = set<pair<ll,ll>,cmp>();


        }

        dp[i] = dp[i-1];

        if(i-ime == k){
            dp[i] = (arr[i]+mf2);
        }
        else{
            dp[i] = (arr[i]+mf1);
        }

        dp[i] = max(mf1,dp[i]);

        s.insert({dp[i],i});
    }

    cout<<max(0ll,*max_element(dp.begin(),dp.end()))<<endl;
}

int main() {

    FIO;
    ll tt=1;

    for(ll i=1;i<=tt;i++){
        solve(i);
    }

    return 0;
}
