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
#define pi pair<int,int>

const int N=2e5+5;
int p[N];


void BuildMySeg(vector<ll>& arr,vector<ll>& seg,ll start,ll end,ll treenode){

    if(start==end){
        seg[treenode] = arr[start];
        return;
    }
    ll mid = (start+end)/2;

    BuildMySeg(arr,seg,start,mid,2*treenode);
    BuildMySeg(arr,seg,mid+1,end,2*treenode + 1);

    // Example:
    // seg[4] -> seg[8] + seg[9];
    // seg[4] -> seg[2*4] + seg[2*4 + 1];

    seg[treenode] = seg[2*treenode] + seg[2*treenode + 1];

}

void UpdateMySeg(vector<ll>& arr,vector<ll>& seg,ll start,ll end,ll treenode,ll idx,ll value){

    if(start==end){
        arr[idx] = value;
        seg[treenode] = value;
        return;
    }

    ll mid = (start+end)/2;
    if(idx>mid){
        //Go Right
        UpdateMySeg(arr,seg,mid+1,end,2*treenode + 1,idx,value);
    }
    else{
        // Go Left
        UpdateMySeg(arr,seg,start,mid,2*treenode,idx,value);
    }

    seg[treenode] = seg[2*treenode] + seg[2*treenode + 1];

}

ll QueryMySeg(vector<ll>& seg,ll start,ll end,ll treenode,ll left,ll right){

    //Three cases
    //1. Completely outside given range
    // Return 0

    if(start>right || end<left){
        return 0;
    }

    //2. Completely inside given range
    // Return tree[treenode]

    if(start>=left && end<=right){
        return seg[treenode];
    }

    //3. Partially Inside and Partially Outside
    // Calculate for left half and right half

    ll mid = (start+end)/2;
    ll leftHalfTreeAnswer = QueryMySeg(seg,start,mid,2*treenode,left,right);
    ll rightHalfTreeAnswer = QueryMySeg(seg,mid+1,end,2*treenode + 1,left,right);

    return leftHalfTreeAnswer + rightHalfTreeAnswer;

}

void solve(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    //Segment Tree is of Size 2*N

    vector<ll> seg(2*n);
    BuildMySeg(arr,seg,0,n-1,1);

    UpdateMySeg(arr,seg,0,n-1,1,1,10);

    //idx(second last arg):Is is the index at which you want to update the value
    //value(last arg):The updated value
    //Here We want to update arr[1] to 10

    //(array,segment_tree_array,start,end,tree_node(index_to_be_filled_in_seg_array));
    //We start filling the seg tree from Index 1

    //Printing Seg tree from Index 1

    for(int i=1;i<2*n;i++){
        cout<<seg[i]<<" ";
    }
    cout<<endl;
    ll ans = QueryMySeg(seg,0,n-1,1,2,5);
    // Here we asked for subarray sum for arr[2:5]
    // After running UpdateMySeg we changed arr[1] = 10
    // a = 1 10 3 4 5 6 7 8 9
    // a[2:5] = 3 4 5 6
    // Sum(a[2:5]) = 3+4+5+6 = 18;
    cout<<ans<<endl;

}

int main() {

    solve();

    
    return 0;
}
