vector<ll> fact(100001);

void fillfactorial(){

    fact[0] = 1;

    fact[1] = 1;

    for(ll i =2;i<=100000;i++){
        fact[i] = (i%mod*fact[i-1]%mod)%mod;
    }
}

ll modulo(ll a, ll b, ll n){
    ll x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
            
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}

ll nCr(ll n,ll r){
    
    fillfactorial();

    // Fermat Little Theorem
    // If m is prime then for integer a
    // the number pow(a,m) - a is an integral
    // multiple of m
    // So, It can be proved that
    // pow(a,m-2)%m = pow(a,-1)%m

    ll a = fact[n]%mod;
    ll b = modulo(fact[r],(ll)mod-2,(ll)mod)%mod;
    ll c = modulo(fact[n-r],(ll)mod-2,(ll)mod)%mod;

    ll val = (a*b)%mod;        

    return (val*c)%mod;
}
