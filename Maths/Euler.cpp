ll euler(ll n){
    
    //Count of integers in range from 1 to n that 
    //have GCD with n is 1(or co-prime to n).

    // phi(n) = n*(1- 1/p1)*(1 - 1/p2)...

    ll res = n;
    ll temp = n;
    for(ll p=2;(p*p)<=temp;p++){
        if(n%p == 0){
            while(n%p == 0){
                n = n/p;
            }
            debug(p);
            res = res - res/p;
        }
    } 

    if(n>1){
        res = res - res/n;
    }

    return res;
}
