/**
*Author:cmefly
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

//Variant Technique Usage like 10101010 and 01010101
//The value of str[i]^(i%2) is 1 for the first string and 0 for the second //string
//Also sometimes try to think Binary
//Sometimes think about array by denoting its elements in bar graph form
//Break into smaller test cases such as n=2 n=3 and n=4
//In transformation type questions focus on the endcase and also see if its unique


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
#define pi pair<int,int>

const int N=2e5+5;
int p[N];

ll modulo(int a, int b, int n){
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

ll value[1000001];
void fillNumberOfDivisorsArray(){
    for(ll i=1;i<=1000000;i++){
        for(ll j=1;i*j<=1000000;j++){
            value[i*j]++;
        }
    }
}

bool SeiveArray[40000];

vector<ll> PrimeNumArray;

void seiveFill(){
    memset(SeiveArray,true,sizeof(SeiveArray));

    SeiveArray[0] = SeiveArray[1] = false;

    for(ll i=2;i<40000;i++){
        if(SeiveArray[i]) PrimeNumArray.pb(i);
        
        for(ll j=i*2;j<40000;j+=i){
            SeiveArray[j] = false;
        }
    }
}

ll PrimeF(ll num){
    ll count = 0;
    
    for(auto n:PrimeNumArray){
        while(num%n==0){
            num = num/n;
            count++;
        }
    }
    if(num>1) count++;

    return count;
}

void addEdge(vector<ll> adj[],ll u,ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

ll __lcm(ll a,ll b){
    return a*b/(__gcd(a,b));
}

class trieNode{

public:
    trieNode* left;
    trieNode* right;    
};   

void insert(ll n,trieNode* head){
    trieNode* curr = head;
    for(ll i=31;i>=0;i--){
        ll currbit = (n>>i)&1;

        if(currbit==0){
            if(!curr->left){
                //left branch is always for 0, right branch is for 1
                curr->left = new trieNode();
            }
            curr = curr->left;
        }
        else{
            if(!curr->right){
                //left branch is always for 0, right branch is for 1
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
}

ll findMaxXorPair(trieNode* head,vector<ll>& arr,ll n){
    ll max_xor = INT_MIN;
    for(ll i=0;i<n;i++){

        trieNode* curr = head;
        ll value = arr[i];
        ll curr_xor = 0;

        for(ll j=31;j>=0;j--){
            ll currbit = (value>>j)&1;

            if(currbit==0){
                if(curr->right){
                    curr_xor += (ll)pow(2,j);
                    curr = curr->right;
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(curr->left){
                    curr_xor += (ll)pow(2,j);
                    curr = curr->left;
                }
                else{
                    curr = curr->right;
                }
            }

            max_xor = max(max_xor,curr_xor);
        }
    }

    return max_xor;
}

void solve(){
    vector<ll> arr{8,1,2,15,10,5};
    trieNode* head = new trieNode();
    for(ll i=0;i<6;i++){
        insert(arr[i],head);
    }  
    cout<<findMaxXorPair(head,arr,6)<<endl;
}

int main() {

    FIO;

    solve();

    
    return 0;
}
