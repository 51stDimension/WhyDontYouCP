ll root(ll num){
    ll l = 0;
    ll r = 1e9 + 1;
    while(l < r-1){
        ll mid = (l+r)/2;
        if(mid*mid > num){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return l;
}
