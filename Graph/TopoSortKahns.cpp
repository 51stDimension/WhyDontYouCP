void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<ll> adj[n+1];

    vector<ll> indegree(n+1);

    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;

        adj[x].pb(y);
        indegree[y]++;
    }

    queue<ll> q;

    for(ll i=1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        ll u = q.front();
        q.pop();
        cout<<u<<" ";
        for(auto v:adj[u]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }

}
