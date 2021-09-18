ll getPar(ll x,vector<ll>& par){

    if(par[x]==x) return x;

    par[x] = getPar(par[x],par);

    return par[x];
}

void unitePar(ll x,ll y,vector<ll>& par,vector<ll>& sz){

    ll p1=getPar(x,par),p2=getPar(y,par);

    if(sz[p1]>sz[p2]){

      par[p2]=p1;
      sz[p1] += sz[p2]+1;
    }
    else{
      par[p1]=p2;
      sz[p2] += sz[p1]+1;
    }

}
