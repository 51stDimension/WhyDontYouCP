ll cycleCount;

void dfs(vector<ll> adj[],ll curr,ll par,ll nodes,vector<bool>& visited){
    visited[curr] = true;
    for(auto u:adj[curr]){
        if(!visited[u]){
            dfs(adj,u,curr,nodes,visited);
        }
        else if(u!=par){
            debug(adj[curr]);
            debug(curr,u);
            cycleCount++;
        }
    }
}

// Total number of cycles = cycleCoun/2
// For example 1-4 4-5 5-1
// Then for this cycles We get a repetition 1-4-5-1(1 was visisted so +1) and then again when we run for 1-4(4 was visited so again +1) SO for one cycle we get 2 increments
