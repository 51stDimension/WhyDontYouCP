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

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define mod 1000000007
#define inf 1e9
#define f(i,n) for(int i=0;i<n;i++)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t) ll tt;cin>>tt;while(tt--)
#define pb push_back
#define endl "\n"

// Problem Statement

// Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

// Input Format
// Number of workers and job: N
// Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

// Sample Input
// 4

// [
// 9 2 7 8
// 6 4 3 7
// 5 8 1 8
// 7 6 9 4
// ]

// Sample Output
// 13

// Constraints
// N <= 20

ll dp[22][(1<<22)];

ll Bitmask(vector<vector<ll>>& cost,ll curr_job,ll n,ll mask){
    if(curr_job >= n){
        return 0;
    }

    if(dp[curr_job][mask]!=-1){
        return dp[curr_job][mask];
    }

    //Otherwise try assigning the current job
    //to all the available people.
    //For example we have 4 people
    //1st and 4th person have already been assigned
    //then out bitmask looks like 0110
    //So before assigning the job check if the bit is set

    ll ans = INT_MAX;

    for(ll person = 0;person<n;person++){
        if(mask&(1<<person)){
            ans = min(ans, cost[curr_job][person]+Bitmask(cost,curr_job+1,n,mask^(1<<person)));
            //If assigning job to a person add the cost and turn off that bit
        }
    }

    return ans;
}

void solve(ll tc){
    ll n;
    cin>>n;  

    memset(dp,-1,sizeof(dp));

    vector<vector<ll>> cost(n,vector<ll>(n,0));

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>cost[i][j];
            //cost[i][j] means assigning the ith person the jth job
        }
    }  

    ll a = Bitmask(cost,0,n,(1<<n)-1);

    cout<<a<<endl;
}   

int main() {

    FIO;
    ll tt = 1;
    for(ll i=1;i<=tt;i++){
        solve(i);
    }

    return 0;
}
