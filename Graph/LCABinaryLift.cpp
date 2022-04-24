void buildUp(vector<ll> adj[],vector<vector<ll>>& up,ll curr,ll par){
    up[curr][0] = par;
    for(ll i=1;i<20;i++){
        if(up[curr][i-1]!=-1){
            up[curr][i] = up[up[curr][i-1]][i-1];
        }
        else{
            up[curr][i] = -1;
        }
    }

    for(auto u:adj[curr]){
        if(u!=par){
            buildUp(adj,up,u,curr);
        }
    }
}

ll lift(ll node,ll jumpsLeft,vector<vector<ll>>& up){
    if(node==-1 || jumpsLeft==0){
        return node;
    }
    for(ll i=20;i>=0;i--){
        if(jumpsLeft&(1<<i)){
            return lift(up[node][i],jumpsLeft^(1<<i),up);
        }
    }
    return -1;
}

void buildLevel(vector<ll> adj[],vector<ll>& level,ll curr,ll par,ll currlevel){
    level[curr] = currlevel;
    for(auto u:adj[curr]){
        if(u!=par){
            buildLevel(adj,level,u,curr,currlevel+1);
        }
    }
}

ll lca(ll u,ll v,vector<ll>& level,vector<vector<ll>>& up){
    //Assuming u should be the deeper node, if not then swap
    if(level[u]<level[v]){
        swap(u,v);
    }

    //Get both of them on the same level by lifting u(deeper node)
    u = lift(u,level[u]-level[v],up);

    if(u==v){
        return u;
    }

    for(ll i=19;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }

    //Now we are sure they are just one level down the lca;
    return lift(u,1,up);
}

void solve(ll tc){
    ll n,q;
    cin>>n>>q;

    vector<ll> adj[n+1];

    for(ll i=2;i<=n;i++){
        ll u;
        cin>>u;
        adj[u].pb(i);
        adj[i].pb(u);
    }      

    vector<vector<ll>> up(n+1,vector<ll>(20));
    vector<ll> level(n+1);

    buildUp(adj,up,1,-1);

    buildLevel(adj,level,1,-1,1);

    for(ll i=0;i<q;i++){
        ll u,v;
        cin>>u>>v;

        cout<<lca(u,v,level,up)<<endl;
    }
}

int main() {

    FIO;
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    ll tt = 1;
    for(ll i=1;i<=tt;i++){
        solve(i);
    }

    return 0;
}
