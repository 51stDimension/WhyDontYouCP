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
    Minimum Coins To Make a Value

    coins[] = {25,10,5} val=30

    o/p = 2

    25 and 5

*/

int getMin(int coins[],int n,int val){

    if(val==0){
        return 0;
    }

    int res = INT_MAX;

    for(int i=0;i<n;i++){

        if(coins[i]<=val){

            int sub_res = getMin(coins,n,val-coins[i]);

            if(sub_res!=INT_MAX){

                res = min(res,sub_res + 1);
            }
        }
    }

    return res;
}

int getMinDP(int coins[],int n,int val){
    int dp[val + 1];
    dp[0]=0;
    for(int i=1;i<=val;i++){
        dp[i] = INT_MAX;
    }
    // dp[i] => Minimum coins required to get value i

    for(int i=1;i<=val;i++){
        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                int sub_res = dp[i - coins[j]];
                if(sub_res!=INT_MAX){
                    dp[i] = min(dp[i],sub_res + 1);
                }
            }
        }
    }

    return dp[val];
}

void solve(){
    // Notes:
    // 
}

int main() {

    FIO;
    
    solve();

    
    return 0;
}
