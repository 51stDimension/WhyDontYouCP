vector<vector<ll>> MatrixExpo(vector<vector<ll>>& a,ll n){

    vector<vector<ll>> result(a.size(),vector<ll>(a.size(),0));

    for(ll i=0;i<a.size();i++){
        result[i][i] = 1;
    }

    while(n){
        if(n&1){
            result = matrixMultiply(result,a);
        }
        a = matrixMultiply(a,a);
        n = n/2;
    }
    return result;
}
