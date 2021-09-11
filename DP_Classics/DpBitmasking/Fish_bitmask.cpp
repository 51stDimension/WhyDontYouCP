#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
double prob[20][20];
double dp[(1<<19)];
 

//Watch Kartik Arora video in youtube
double pMove(int prev_bitMask, int j, int& n)
{
    int k = __builtin_popcount(prev_bitMask);
    ll den = (k * (k - 1))/2;
    double moveProbab = 0;
    for(int fish = 0; fish < n; fish++)
    {
        if((1<<fish)&prev_bitMask)
            moveProbab += prob[fish + 1][j+1];
    }
    return moveProbab/(1.0*den);
}
 
double solve(int bitMask, int& n)
{
    int alive = __builtin_popcount(bitMask);
 
    if(alive == n)
        return 1;
    if(dp[bitMask] > -0.9)
        return dp[bitMask];
 
    double answer = 0;
    for(int fish = 0; fish < n; fish++)
    {
        if(!(bitMask & (1<<fish))){

            //If 'fish' is dead make it alive and calculate ways to
            //reach from that previous state to this state.

            int prev_bitMask = bitMask^(1<<fish);//Previous bitmask making that fish alive
            //Suppose current state is 00100, we make a fish alive that is 00101
            //pmove calculates number of ways we can reach 0010<-00101 by conducting different fights and killing that fish which was made alive
            double prev_day = solve(prev_bitMask, n);//Calculate ways to reach 00101 by again making fishes live and killing them
            answer += prev_day*pMove(prev_bitMask, fish, n);
        }
    }
    return dp[bitMask] = answer;
}
 
int main() {
   fast_io;
   int t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
       cin >> n;
       memset(dp, -1, sizeof dp);
       rep(i,1,n+1)rep(j,1,n+1)cin >> prob[i][j];
       rep(i,0,n)
        prDouble(solve((1 << i), n)) << ' ';
        //Only keeping one single fish alive in the end throuhg bit mask
        //Suppose 5 fishes
        //We keep fish 3 alive that is 00100
        //Then from here we calculate all ways to go to 11111
        //By making fishes alive in previous states
 
   }
 
   return 0;
}
