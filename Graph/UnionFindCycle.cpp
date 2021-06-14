ll find(vector<ll>& dsu,ll node){
    if(dsu[node]==-1){
        return node;
    }

    return find(dsu,dsu[node]);
}

void Union(vector<ll>& dsu, int x, int y)
{
    dsu[x] = y;
}
