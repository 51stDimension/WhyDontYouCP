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
    Longest Common Subsequence

    ABCDGH
    AEDFHR

    If mismatch H!=R -> Two options -> ABCDG & AEDFHR
                                       ABCDGH & AEDFH

    If match just do i-1 and j-1 and +1
*/
int lcs(string s1,string s2,int m,int n){
    if(m==0 || n==0){
        return 0;
    }

    if(s1[m-1] == s2[n-1]){
        return 1 + lcs(s1,s2,m-1,n-1);
    }
    else{
        max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
    }
}

int lcsDP(string s1,string s2){

    int m = s1.length();
    int n = s2.length();

    int dp[m+1][n+1];

    for(int i=0;i<=m;i++){
        dp[i][0] = 0;
    }

    for(int i=0;i<=n;i++){
        dp[0][i] = 0;
    }

    // dp[i][j] = length of lcs for s1(0..i-1) && s2(0..j-1)
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

void solve(){
    // Notes:
    // Learn how to print the LCS
}

int main() {

    FIO;
    
    solve();

    
    return 0;
}
