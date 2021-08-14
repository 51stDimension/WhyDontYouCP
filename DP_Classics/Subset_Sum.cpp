bool isSubsetSum(vector<ll> arr,ll sum){

    ll n = arr.size();

    bool subset[n+1][sum+1];

    //Sum is 0
    for(ll i=0;i<=n;i++){
        subset[i][0] = true;
    }

    //Sum is not 0 but elements are 0
    for(ll i=1;i<=sum;i++){
        subset[0][i] = false;
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=sum;j++){
            if(arr[i-1]>j){
                subset[i][j] = subset[i-1][j];
            }
            else{
                subset[i][j] = subset[i-1][j] || subset[i-1][j-arr[i-1]];
            }
        }
    }

    return subset[n][sum];
}
