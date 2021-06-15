void addEdge(vector<ll> adj[],ll u,ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

bool DFSmain(vector<ll> adj[],ll s,vector<bool>& visited,ll parent){
    visited[s] = true;
    for(auto u:adj[s]){
        if(visited[u]==false){
            if(DFSmain(adj,u,visited,s)==true){
                return true;
            }
        }
        else if(u!=parent){
            return true;
        }
    }
    return false;
}

bool DFSUtil(vector<ll> adj[],ll vertices){
    vector<bool> visited(vertices+1,false);
    for(ll i=0;i<vertices;i++){
        if(visited[i]==false){
            if(DFSmain(adj,i,visited,-1)==true){
                return true;
            }
        }
    }
    return false;
}

void solve(){
    ll vertices,edges;
    cin>>vertices>>edges;

    vector<ll> adj[vertices];

    for(ll i=0;i<edges;i++){
        ll u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }

    bool ans = DFSUtil(adj,vertices);
    cout<<ans<<endl;

}

int main() {

    FIO;
    
        solve();

    
    return 0;
}
