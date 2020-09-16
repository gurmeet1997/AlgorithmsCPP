#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define ll             long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(test)            int test; cin>>test; while(test--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// bool comp(int a,int b){
//    if(a>0&&b<0)
//    	return true;
//    if((a==0&&b<0)||(a>0&&b==0))
//    	 return true;
//    if((a>0&&b>0)||(a<0&&b<0)||(a<0&&b>0))
//    	 return false;
//    if((a==0&&b>0)||(a<0&&b==0))
//    	 return false;
// }

int dp[11][51];
int solve(ll e,ll f){
    if(f==0||f==1)
       return f;
    if(e==1)
       return f;
    if(dp[e][f]!=-1)
      {
        return dp[e][f];
      }
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
      int l,h;
      if(dp[e-1][k-1]!=-1){
        l=dp[e-1][k-1];
      }
      else{
        l=solve(e-1,k-1);
        dp[e-1][k-1]=l;
      }
      if(dp[e][f-k]!=-1){
        h=dp[e][f-k];
      }
      else{
        h=solve(e,f-k);
        dp[e][f-k]=h;
       }

   int tempans=1+max(l,h);
   if(tempans<mn){
    mn=tempans;
   }


    }
    return dp[e][f]=mn;



}


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
  w(test){
         ll e,f;
         cin>>e>>f;
         memset(dp,-1,sizeof(dp));
         int result=solve(e,f);
         cout<<result<<"\n";


      }

}


int32_t main()
{
	c_p_c();
	return 0;
}