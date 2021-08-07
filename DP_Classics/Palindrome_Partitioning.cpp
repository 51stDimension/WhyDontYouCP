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
    Palindrome Partitioning Optimized

    string = "geek"
    
    Minimize the partition:

    Minimum cuts needed for "geek": 2 i.e after g and after second e
    making three substrings i,e g,ee,k:All three are palindromes

*/

int PalPartDP(string s){

	int n = s.length();

	bool isPalin[n][n];

	for(ll i=0;i<n;i++){
		isPalin[i][i] = true;
	}

	for(ll gap=1;gap<n;gap++){

		for(ll i=0;i<n-gap;i++){

			ll j = i+gap;

			if(j>i && (s[i]==s[j] && (j==i+1 || isPalin[i+1][j-1]))){

				isPalin[i][j] = true;

			}
			else{
				isPalin[i][j] = false;
			}
		}
	}	

	// isPalin[i][j] == true iff substring from s[i..j] is a palindrome

	ll dp[n];

	for(ll j=0;j<n;j++){
		ll min_cut = j;

		for(ll i=0;i<=j;i++){

			if(isPalin[i][j]){

				min_cut = min(min_cut,(i==0)?0:dp[i-1]+1);

			}
		}

		dp[j] = min_cut;
	}

	return dp[n-1];
}





void solve(){
    // Notes:

    // This is a O(n^2) approach
    // Video Explaination: https://www.youtube.com/watch?v=HUeUmrQy9cs

    string s;
    cin>>s;
    cout<<PalPartDP(s);
}

int main() {

    FIO;
    
    solve();

    
    return 0;
}
