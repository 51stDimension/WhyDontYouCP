/**
* @Author:51D
**/
#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <climits>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

typedef long long ll;

#define mod 1000000007
#define inf 1e9
#define f(i,n) for(int i=0;i<n;i++)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t) ll tt;cin>>tt;while(tt--)
#define pb push_back
#define endl "\n"
#define read(arr,n) for(ll i=0;i<n;i++){cin>>arr[i];};
#define pi pair<ll,ll>
#define all(arr) arr.begin(),arr.end()

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
//Focus and Keep it Simple
//Binary Search when asked for a minimum single number
ll gp(ll base,ll power){

    // Fermat Little Theorem
    // If m is prime then for integer a
    // the number pow(a,m) - a is an integral
    // multiple of m
    // So, It can be proved that
    // pow(a,m-2)%m = pow(a,-1)%m

    ll numerator = ((modulo(base,power+1,mod) - 1+mod)%mod);
    ll denominator = modulo(base-1,mod-2,mod);

    return (numerator%mod * denominator%mod)%mod;
}


void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> prime(n),expo(n);

    for(ll i=0;i<n;i++){
        cin>>prime[i]>>expo[i];
    }

    //Number Of Divisors
    ll number_of_divisors = 1;
    for(ll i=0;i<n;i++){
        (number_of_divisors *= (expo[i]+1)) %= mod;
    }

    //Sum Of Divisors
    ll sum_of_divisors = 1;
    for(ll i=0;i<n;i++){
        (sum_of_divisors *= gp(prime[i],expo[i])) %= mod;
    }


    //Calculation this again for proper division
    ll out_expo = 1;//Number of divisors by 2

    bool has_odd_expo = false;

    ll odd_expo_index = -1;

    for(ll i=0;i<n;i++){
        if(expo[i]%2 == 1){ 

            has_odd_expo = true;
            odd_expo_index = i;

        }
    }

    ll product_of_divisors = 1;

    if(has_odd_expo){
        for(ll i=0;i<n;i++){
            if(i==odd_expo_index){
                (out_expo *= (expo[i]+1)/2) %= (mod-1);
            }
            else{
                (out_expo *= (expo[i]+1)) %= (mod-1);
            }
        }
        for(ll i=0;i<n;i++){
            (product_of_divisors *= modulo(prime[i],(expo[i]*out_expo)%(mod-1),mod)) %= mod;
        }
    }
    else{
        for(ll i=0;i<n;i++){
            (out_expo *= (expo[i]+1)) %= (mod-1);
        }
        for(ll i=0;i<n;i++){
            (product_of_divisors *= modulo(prime[i],(expo[i]*out_expo/2)%(mod-1),mod)) %= mod;
        }
    }
    
    cout<<number_of_divisors<<" "<<sum_of_divisors<<" "<<product_of_divisors<<endl;
}

int main() {

    FIO;
    ll tt;
    tt = 1;
    for(ll i=1;i<=tt;i++){
        solve(i);
    }

    return 0;
}
