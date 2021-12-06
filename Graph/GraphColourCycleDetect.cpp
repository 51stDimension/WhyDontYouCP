void dfs(int curr,int par){
    // col == 0 means: yet to be visited
    // col == 1 means: visited and in call stack
    // col == 2 means: visisted and not in call stack
    
    col[curr] = 1;
    for(auto u:adj[curr]){
        if(col[u]==0){
            dfs(u,curr);
        }
        else if(u!=par && col[u]==1){
            cycleDetected = true;
        }
    }
    col[curr] = 2;
}
