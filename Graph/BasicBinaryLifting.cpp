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

    buildUp(adj,up,1,-1);

    for(ll i=0;i<q;i++){
        ll node,jumps;
        cin>>node>>jumps;

        cout<<lift(node,jumps,up)<<endl;
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
