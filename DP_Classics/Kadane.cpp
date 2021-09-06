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


const int N=2e5+5;
const long long infll = 0x3f3f3f3f3f3f3f3fLL;
int p[N];

//Maximum Sum Subarray

ll maxSum(vector<ll>& arr,ll n){

    vector<ll> dp(n+1);
    dp[0] = arr[0]>0?arr[0]:0;

    ll max_so_far = dp[0];

    for(ll i=1;i<n;i++){
        dp[i] = dp[i-1] + arr[i];
        //For Space optimized version just keep two different variables instead of whole dp array as the value of dp[i] depends only on dp[i-1]
        //Handle Special case for all elements negative 
        if(dp[i]<0){
            dp[i] = 0;
        }
        max_so_far = max(dp[i],max_so_far);
    }

    return max_so_far;
}

void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> arr(n);

    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<maxSum(arr,n);
}

int main() {

    FIO;
    ll tt=1;
    for(ll i=1;i<=tt;i++){
        solve(i);
    }

    return 0;
}
