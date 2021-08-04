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
    Longest Increasing Subsequence

*/

int LIS(int arr[],int n){
    
    int lis[n];

    lis[0] = 1;

    for(int i=1;i<n;i++){
        lis[i] = 1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                lis[i] = max(lis[i],lis[j]+1);
            }
        }
    }

    int res = lis[0];
    for(int i=1;i<n;i++){
        res = max(res,lis[i]);
    }

    return res;
}

void solve(){
    // Notes:
    // Revise the O(nlogn) method using tail array and binary search(Upper_Bound)
}

int main() {

    FIO;
    
    solve();

    
    return 0;
}
