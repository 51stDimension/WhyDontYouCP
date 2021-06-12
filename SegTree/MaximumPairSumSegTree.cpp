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

void BuildSeg(vector<ll>& arr,vector<pi>& seg,ll start,ll end,ll treenode){

    if(start==end){
        seg[treenode].first = 0;
        seg[treenode].second = arr[start];
        return;
    }

    ll mid = (start+end)/2;
    BuildSeg(arr,seg,start,mid,2*treenode);
    BuildSeg(arr,seg,mid+1,end,2*treenode + 1);

    ll leftsmax,leftmax,rightsmax,rightmax;

    leftsmax = min(seg[2*treenode].first,seg[2*treenode].second);
    leftmax  = max(seg[2*treenode].first,seg[2*treenode].second);
    rightsmax = min(seg[2*treenode+1].first,seg[2*treenode+1].second);
    rightmax  = max(seg[2*treenode+1].first,seg[2*treenode+1].second);

    seg[treenode].first = max(leftmax,rightmax);
    seg[treenode].second = min(max(leftsmax,rightmax),max(rightsmax,leftmax));
}

pi QuerySeg(vector<ll>& arr,vector<pi>& seg,ll start,ll end,ll treenode,ll left,ll right){

    if(start>right || end<left){
        return {0,0};
    }

    if(start>=left && end<=right){
        return seg[treenode]; 
    }

    ll mid = (start+end)/2;
    pi LeftTree = QuerySeg(arr,seg,start,mid,2*treenode,left,right);
    pi RightTree = QuerySeg(arr,seg,mid+1,end,2*treenode + 1,left,right);

    pi ans;

    ll leftsmax,leftmax,rightsmax,rightmax;

    leftsmax = min(LeftTree.first,LeftTree.second);
    leftmax  = max(LeftTree.first,LeftTree.second);
    rightsmax = min(RightTree.first,RightTree.second);
    rightmax  = max(RightTree.first,RightTree.second);

    ans.first = max(leftmax,rightmax);
    ans.second = min(max(leftsmax,rightmax),max(rightsmax,leftmax));

    return ans;
}

void UpdateSeg(vector<ll>& arr,vector<pi>& seg,ll start,ll end,ll treenode,ll idx,ll value){

    if(start==end){
        arr[idx] = value;
        seg[treenode].second = value;
        return;
    }


    ll mid = (start+end)/2;
    if(idx>mid){
        
        UpdateSeg(arr,seg,mid+1,end,2*treenode + 1,idx,value);
    }
    else{
        UpdateSeg(arr,seg,start,mid,2*treenode,idx,value);
        
    }

    ll leftsmax,leftmax,rightsmax,rightmax;

    leftsmax = min(seg[2*treenode].first,seg[2*treenode].second);
    leftmax  = max(seg[2*treenode].first,seg[2*treenode].second);
    rightsmax = min(seg[2*treenode+1].first,seg[2*treenode+1].second);
    rightmax  = max(seg[2*treenode+1].first,seg[2*treenode+1].second);

    seg[treenode].first = max(leftmax,rightmax);
    seg[treenode].second = min(max(leftsmax,rightmax),max(rightsmax,leftmax));

}

void solve(){
     ll n;cin>>n;vector<ll> arr(n);
     for(ll i=0;i<n;i++){
        cin>>arr[i];
     }
     ll q;cin>>q;
     vector<pi> seg(4*n);
     
     BuildSeg(arr,seg,0,n-1,1);
    
     // cout<<seg.size()<<endl;
     while(q--){
        char a;
        ll p,k;
        cin>>a>>p>>k;
        if(a=='Q'){
            pi pairans = QuerySeg(arr,seg,0,n-1,1,p-1,k-1);
            cout<<pairans.first+pairans.second<<endl;   
        }
        else{
            UpdateSeg(arr,seg,0,n-1,1,p-1,k);
        }
     }  
     
}

int main() {

    FIO;

    solve();

    
    return 0;
}
