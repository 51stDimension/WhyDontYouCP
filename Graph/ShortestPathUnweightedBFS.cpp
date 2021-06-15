//Shortest Path in an Unweighted Graph using BFS

void addEdge(vector<ll> adj[],ll u,ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

void BFS(vector<ll> adj[],vector<ll>& dist,ll s,ll vertices){
    vector<bool> vistied(vertices + 1,false);
    vistied[s] = true;
    queue<ll> q;
    q.push(s);

    while(q.empty()==false){
        ll u = q.front();
        q.pop();
        for(auto v:adj[u]){
            if(vistied[v]==false){
                dist[v] = dist[u] + 1;
                q.push(v);
                vistied[v] = true;
            }    
        }
    }
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

    vector<ll> dist(vertices,INT_MAX);
    ll s = 0;//source = 0;
    dist[s] = 0;
    BFS(adj,dist,0,vertices);
    
    for(int i=0;i<vertices;i++){
        cout<<"dist from "<<s<<" to "<<i<<":";
        cout<<dist[i]<<endl;
    }
}

int main() {

    FIO;
    
        solve();

    
    return 0;
}
