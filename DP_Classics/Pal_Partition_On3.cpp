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
    Palindrome Partitioning

    string = "geek"
    
    Minimize the partition:

    Minimum cuts needed for "geek": 2 i.e after g and after second e
    making three substrings i,e g,ee,k:All three are palindromes

*/

bool isPalindrome(string s,int i,int j){
    ll left = i;
    ll right = j;
    while(left<=right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
    }

    return true;
}
int PalPartRec(string s,ll i,ll j){
    if(isPalindrome(s,i,j)){
        return 0;
    }

    ll ans = INT_MAX;

    for(ll cut = i;cut<j;cut++){
        ans  = min(ans,1LL+PalPartRec(s,i,cut)+PalPartRec(s,cut+1,j));
    }

    return ans;
}

int PalPartDP(string s){

    ll n = s.length();


    ll dp[n][n];
    bool isPalin[n][n];

    // dp[i][j] = Minimum cuts required for substring s[i..j]

    for(ll i=0;i<n;i++){
        dp[i][i] = 0;
        isPalin[i][i] = true;
    }


    for(ll diffbwi_j=1 ; diffbwi_j<n ; diffbwi_j++){

        // diffbwi_j is gap between i and j
        // gap/diffbwi_j=1
        //     i=0
        //         j=1
        //     i=1
        //         j=2
        //     i=2 (This is the max value of i for gap=1 i.e i<n-gap)
        //         j=3

        for(ll i=0;i<n-diffbwi_j;i++){

            ll j = i+diffbwi_j;

            if(s[i]==s[j] && (isPalin[i+1][j-1] || diffbwi_j==1)){
                dp[i][j] = 0;
                isPalin[i][j] = true;
            }

            else{

            	isPalin[i][j] = false;
                dp[i][j] = INT_MAX;
                for(ll k=i;k<j;k++){
                    dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[k+1][j]);

                    //Suppose i=0 and j=3
                    // Then the paritions that we can make are
                    // dp[0][3] = min(1+dp[0][0]+dp[1][3]
                    //                1+dp[0][1]+dp[2][3]
                    //                1+dp[0][2]+dp[3][3]);

                }
            }
        }

    }
    
    return dp[0][n-1];

}


void solve(){
    // Notes:
    
    // This is a O(n^3) approach

    string s;
    cin>>s;
    cout<<PalPartDP(s);
}

int main() {

    FIO;
    
    solve();

    
    return 0;
}
