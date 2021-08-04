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
    Edit Distance Problem

    Given two strings s1 and s2;

    Convert s1 -> s2 in min number of operations

    Given three operations

    Replace a character
    Delete a character
    Insert a character

*/

int eD(string s1,string s2,int m,int n){

    if(m==0){
        return n;
    }

    if(n==0){
        return m;
    }

    if(s1[m-1]==s2[n-1]){
        return eD(s1,s2,m-1,n-1);
    }

    else{
        return 1 + min(eD(s1,s2,m,n-1),eD(s1,s2,m-1,n),eD(s1,s2,m-1,n-1));
        //         Insert              Delete          Replace
        //Considering s1->s2
    }
}

int eDP(string s1,string s2,int m,int n){
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=n;j++){
        dp[0][j] = j;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }

    return dp[m][n];
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
