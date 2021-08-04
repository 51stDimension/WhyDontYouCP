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

const int N=2e5+5;
const long long infll = 0x3f3f3f3f3f3f3f3fLL;
int p[N];

/*
    Coin Change(Count Combinations)

    coins[] = {1,2,3} sum=4
    o/p = 4

    4 = 2+1+1
    4 = 1+1+1+1
    4 = 2+2
    4 = 1+3
    
    imp: Infinite Supply Of Every Count Type
*/

int getCount(int coins[],int n,int sum){

    if(sum==0) return 1;

    if(n==0) return 0;

    int res = getCount(coins,n-1,sum);
    if(coins[n-1]<=sum){
        res = res + getCount(coins,n,sum - coins[n-1]);
    }

    return res;
}

int getCountDP(int coins[],int n,int sum){

    int dp[sum+1][n+1];
    // dp[i][j] = Number of combinations we can get with sum
    //            i and coins from index 1 to index j

    for(int i=0;i<=n;i++){
        dp[0][i] = 1;
    }
    for(int i=1;i<=sum;i++){
        dp[i][0] = 1;
    }

    for(int i=1;i<=sum;i++){
        for(int j=1;j<=n;j++){
            
            dp[i][j] = dp[i][j-1];
            
            if(coins[j-1]<=i){
                dp[i][j] += dp[i-coins[j-1]][j];
            }
        }
    }

    return dp[sum][n];
}

void solve(){
    // Notes:
    // 2+1+1 is same is 1+1+2
}

int main() {

    FIO;
    
    solve();

    
    return 0;
}
