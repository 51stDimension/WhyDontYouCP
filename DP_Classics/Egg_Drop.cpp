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
    Egg Dropping Puzzle

    Count the minimum number of trials needed to get the threshold floor

    Let res(f,e) be the minimum trials in the worst case
    for f floors and e eggs

    res(f,e) = for(x=1 to x=f)min({ max(res(x-1,e-1),res(f-x,e))})+1
                                  //Breaks         //Doesnt Break
    Base cases:
    res(f,1) = f
    res(1,e) = 1
    res(0,e) = 0

    In res(f,e) the first argument goes from 0 to f
    the second argument goes from 1 to e
    So DP array of dp[f+1][e+1]
*/

int eggDropDP(int e,int f){
    int dp[f+1][e+1];
    //Zero'th column is dummy column(Made for ease of implementation)

    for(int i=1;i<=e;i++){
        dp[1][i] = 1;
        dp[0][i] = 0;
    }

    for(int j=1;j<=f;j++){
        dp[j][1] = j;
    }

    for(int i=2;i<=f;i++){
        for(int j=2;j<=e;j++){
            dp[i][j] = INT_MAX;
            //Go from bottom to i'th floor
            for(int x=1;x<=i;x++){
                dp[i][j] = min(dp[i][j],1+max(dp[x-1][j-1],dp[i-x][j]));
            }
        }
    }

    return dp[f][e];
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
