//visited[curr] == 0 means not visited
//visited[curr] == 1 means color assigned is 1
//visited[curr] == 2 means color assigned is 2
bool checkBipartite(vector<ll> adj[],ll curr,vector<ll>& visited,ll par,ll color){
    visited[curr] = color;
    for(auto u:adj[curr]){
        if(visited[u]==0){
            bool subprob = checkBipartite(adj,u,visited,curr,3-color);
            if(!subprob){
                return false;
            }
        }
        else if(u!=par && color==visited[u]){
            return false;
        }
    }

    return true;
}
void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<ll> adj[n+1];

    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<ll> visited(n+1);

    cout<<checkBipartite(adj,1,visited,-1,1);
}
