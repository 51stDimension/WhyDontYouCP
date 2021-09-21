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

// Matrix Chain Multiplication

// dp[x][y] = min(dp[x][k] + dp[k+1][y]; for all k belonging to [x,y-1])
// arr[] = {2,1,3,4} //Represents 3 matrices
// M1 -> 2*1
// M2 -> 1*3
// M3 -> 3*4
// For (M1*(M2*M3)) => 0 + 1*3*4 + 2*1*4(As after multiplying m2*m3 we get a matrix of size 1*4 which so then we need to multiply it with a mtrix of 2*1)
//                      (for m2*m3)

//Different ways to make partitions

ll MCMRecurse(vector<ll>& arr,ll i,ll j){
    if(i+1 == j){
        return 0;
    }

    ll res = INT_MAX;

    for(ll k=i+1;k<j;k++){
        res = min(res,MCMRecurse(arr,i,k)
                     +MCMRecurse(arr,k,j)
                     +(arr[i]*arr[k]*arr[j]));
    }

    return res;
}

ll MCMTabulate(vector<ll>& arr,ll n){
    ll dp[n][n];

    for(ll i=0;i<n-1;i++){
        dp[i][i+1] = 0;
    }

    for(ll gap=2;gap<n;gap++){

        for(ll i=0;(i+gap)<n;i++){

            ll j = i+gap;
            dp[i][j] = INT_MAX;

            for(ll k=i+1;k<j;k++){

                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+(arr[i]*arr[j]*arr[k]));

            }
        }
    }

    return dp[0][n-1];
}

void solve(ll tc){

    vector<ll> arr{20,10,30,40};

    ll n = arr.size();

    cout<<MCMRecurse(arr,0,n-1)<<endl;

    cout<<MCMTabulate(arr,n)<<endl;
}

int main() {

    FIO;
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    ll tt=1;
    for(ll i=1;i<=tt;i++){
        solve(i);
    }

    return 0;
}
