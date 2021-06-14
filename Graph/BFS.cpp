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


void addEdge(vector<ll> adj[],ll u,ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

//BFS follows the shortest path concept
void BFS(vector<ll> adj[],int v,int s){

    vector<bool> visited(v+1,false);
    
    queue<ll> q;
    
    visited[s] = true;
    
    //s stands for source(from where we want to start BFS)
    q.push(s);
    
    while(q.empty()==false){
        
        ll u = q.front();
        q.pop();
        
        cout<<u<<" ";
        
        for(auto elem:adj[u]){
            
            if(visited[elem]==false){
                q.push(elem);
                visited[elem] = true;
            
            }
        }
    }
}

void solve(){

    ll edges,vertices;
    cin>>edges>>vertices;

    vector<ll> adj[vertices];

    for(ll i=0;i<edges;i++){
        ll u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }

    BFS(adj,vertices,0);

}

int main() {

    FIO;

    solve();

    
    return 0;
}
