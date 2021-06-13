/**
*Author:cmefly
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
#define read(n) ll n;cin>>n;vector<int> arr(n);for(int i=0;i<n;i++){cin>>arr[i];};
#define pi pair<ll,ll>

const int N=2e5+5;
int p[N];

ll modulo(int a, int b, int n){
    ll x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
            
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}

ll value[1000001];
void fillNumberOfDivisorsArray(){
    for(ll i=1;i<=1000000;i++){
        for(ll j=1;i*j<=1000000;j++){
            value[i*j]++;
        }
    }
}

bool SeiveArray[40000];

vector<ll> PrimeNumArray;

void seiveFill(){
    memset(SeiveArray,true,sizeof(SeiveArray));

    SeiveArray[0] = SeiveArray[1] = false;

    for(ll i=2;i<40000;i++){
        if(SeiveArray[i]) PrimeNumArray.pb(i);
        
        for(ll j=i*2;j<40000;j+=i){
            SeiveArray[j] = false;
        }
    }
}

ll PrimeF(ll num){
    ll count = 0;
    
    for(auto n:PrimeNumArray){
        while(num%n==0){
            num = num/n;
            count++;
        }
    }
    if(num>1) count++;

    return count;
}
struct node{
    ll totalSum;
    ll MaxSubSum;
    ll BestPrefixSum;
    ll BestSuffixSum;
};

void BuildSeg(vector<ll>& arr,vector<node>& seg,ll start,ll end,ll treenode){

    if(start==end){
        seg[treenode].totalSum = arr[start];
        seg[treenode].MaxSubSum = arr[start];
        seg[treenode].BestPrefixSum = seg[treenode].BestSuffixSum = arr[start];
        return;
    }

    ll mid = (start+end)/2;
    BuildSeg(arr,seg,start,mid,2*treenode);
    BuildSeg(arr,seg,mid+1,end,2*treenode + 1);

    node leftHalf = seg[2*treenode];
    node rightHalf = seg[2*treenode + 1];

    seg[treenode].totalSum = leftHalf.totalSum + rightHalf.totalSum;
    seg[treenode].BestPrefixSum = max(leftHalf.BestPrefixSum, leftHalf.totalSum + rightHalf.BestPrefixSum);
    seg[treenode].BestSuffixSum = max(rightHalf.BestSuffixSum, rightHalf.totalSum + leftHalf.BestSuffixSum);
    seg[treenode].MaxSubSum = max( leftHalf.MaxSubSum ,max( rightHalf.MaxSubSum ,max( leftHalf.totalSum + rightHalf.BestPrefixSum ,max( rightHalf.totalSum + leftHalf.BestSuffixSum , leftHalf.BestSuffixSum + rightHalf.BestPrefixSum ))));
}

node QuerySeg(vector<ll>& arr,vector<node>& seg,ll start,ll end,ll treenode,ll left,ll right){

    if(start>right || end<left){
        return {-100000, -100000, -100000, -100000};
    }

    if(start>=left && end<=right){
        return seg[treenode]; 
    }

    ll mid = (start+end)/2;

    node leftHalf = QuerySeg(arr,seg,start,mid,2*treenode,left,right);
    node rightHalf = QuerySeg(arr,seg,mid+1,end,2*treenode + 1,left,right);

    node ans;

    ans.totalSum = leftHalf.totalSum + rightHalf.totalSum;
    ans.BestPrefixSum = max(leftHalf.BestPrefixSum, leftHalf.totalSum + rightHalf.BestPrefixSum);
    ans.BestSuffixSum = max(rightHalf.BestSuffixSum, rightHalf.totalSum + leftHalf.BestSuffixSum);
    ans.MaxSubSum = max( leftHalf.MaxSubSum ,max( rightHalf.MaxSubSum ,max( leftHalf.totalSum + rightHalf.BestPrefixSum ,max( rightHalf.totalSum + leftHalf.BestSuffixSum , leftHalf.BestSuffixSum + rightHalf.BestPrefixSum ))));


    return ans;
}


void solve(){
     ll n;cin>>n;vector<ll> arr(n);
     for(ll i=0;i<n;i++){
        cin>>arr[i];
     }
     vector<node> seg(4*n);
     BuildSeg(arr,seg,0,n-1,1);
     ll q;cin>>q;
     while(q--){
        // char a;
        ll p,k;
        cin>>p>>k;
        node pairans = QuerySeg(arr,seg,0,n-1,1,p-1,k-1);
        cout<<pairans.MaxSubSum<<endl;
     }  
     
}

int main() {

    FIO;

    solve();

    
    return 0;
}
