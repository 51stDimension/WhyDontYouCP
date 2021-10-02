vector<vector<ll>> matrixMultiply(vector<vector<ll>>& a,vector<vector<ll>>& b){

    ll R1 = a.size();
    ll C1 = a[0].size();

    ll R2 = b.size();
    ll C2 = b[0].size();

    vector<vector<ll>> ans(R1,vector<ll>(C2,0));

    for(ll i=0;i<R1;i++) {
        for(ll j=0;j<C2;j++) { 
            for(ll k=0;k<R2;k++) {
                (ans[i][j] += (a[i][k]%mod * b[k][j]%mod)%mod) %= mod;
            }
        } 
    }

    return ans;
}
