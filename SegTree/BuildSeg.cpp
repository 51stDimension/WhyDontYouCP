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

    //(array,segment_tree_array,start,end,tree_node(index_to_be_filled_in_seg_array));
    //We start filling the seg tree from Index 1

    //Printing Seg tree from Index 1
    // for(int i=1;i<2*n;i++){
    //     cout<<seg[i]<<" ";
    // }

}

int main() {

    solve();

    
    return 0;
}
