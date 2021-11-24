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

using namespace std;

typedef long long ll;

#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t) ll tt;cin>>tt;while(tt--)
#define pb push_back
#define endl "\n"

void fillLPS(string str,ll n,vector<ll>& lps){
	lps[0] = 0;
	ll len = 0;
	ll i=1;

	while(i<n){
		if(str[i] == str[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len == 0){
				lps[i++] = 0;
			}
			else{
				len = lps[len-1];
			}
		}
	}
}


// Resource referred: https://www.youtube.com/watch?v=cH-5KcgUcOE
void KMP(string pat,string txt){

	ll n = txt.length();
	ll m = pat.length();

	vector<ll> lps(m);

	fillLPS(pat,m,lps);

	ll i = 0;
	ll j = 0;

	while(i<n){
		if(txt[i] == pat[j]){
			i++;
			j++;
		}

		if(j==m){
			cout<<"Found a pattern at "<<(i-j)<<endl;
			j = lps[j-1];
		}
		else if(i<n && txt[i]!=pat[j]){
			if(j==0){
				i++;
			}
			else{
				j = lps[j-1];
			}
		}
	}
}

void solve(ll tc){
	string pat,txt;
	cin>>pat>>txt;

	KMP(pat,txt);
}

int main() {

    ll tt = 1;
    for(ll i=1;i<=tt;i++){
        solve(i);
    }

    return 0;
}
