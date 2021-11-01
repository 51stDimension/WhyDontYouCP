ll getPar(ll x,vector<ll>& par){

    if(par[x]==x) return x;
    
    //Path compression optimisation
    par[x] = getPar(par[x],par);

    return par[x];
}
  
//Initialize the sz with vector with 1s
void unitePar(ll x,ll y,vector<ll>& par,vector<ll>& sz){

    ll p1=getPar(x,par),p2=getPar(y,par);

    if(sz[p1]>sz[p2]){

      par[p2]=p1;
      sz[p1] += sz[p2];
    }
    else{
      par[p1]=p2;
      sz[p2] += sz[p1];
    }

}

ll KruskalMST(vector<vector<ll>>& edgeList,vector<ll>& par,vector<ll>& sz){

    ll ans = 0;

    for(auto edge:edgeList){

      int w = edge[0];
      int x = edge[1];
      int y = edge[2];

      //take that edge in MST iff both belong to different set
      //and joining them wont make a cycle.

      if(getPar(x,par)!=getPar(y,par)){
        unitePar(x,y,par,sz);
        ans += w;
      }

    }

    return ans;
}

int main(){

    ll vertices,edges;
    cin>>vertices>>edges;

    vector<vector<ll>> edgeList;

    for(ll i=0;i<edges;i++){
      ll x,y,w;
      cin>>x>>y>>w;
      edgeList.pb({w,x,y});
    }

    vector<ll> par(vertices+1);
    for(ll i=1;i<=vertices;i++){
      par[i] = i;
    }

    vector<ll> sz(vertices+1,1);

    //Step1: Sort edgeList
    sort(edgeList.begin(),edgeList.end());

    auto ans = KruskalMST(edgeList,par,sz);

    return 0;
}
