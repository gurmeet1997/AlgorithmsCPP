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


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
  w(test){

  	    
  		ll sum,c;
      cin>>sum>>c;
      int coin[c];
      for(int i=0;i<c;i++)
         cin>>coin[i];
      int dp[c+1][sum+1];
      for(int j=0;j<sum;j++){
        dp[0][j]=INT_MAX-1;
      }
      for(int j=0;j<=sum;j++){
        
       if(j%coin[0]==0){
        dp[1][j]=j/coin[0];
       }
       else{
        dp[1][j]=INT_MAX-1;
       }
     }
        for(int i=2;i<=c;i++){
          for(int j=0;j<=sum;j++){
            if(coin[i-1]<=j){
              dp[i][j]=min(1+dp[i-1][j-coin[i-1]],dp[i-1][j]);
            }
            else{
              dp[i][j]=dp[i-1][j];
            }
          }
        }

  cout<<dp[c][sum]<<"\n";

  		}

  
  }


int32_t main()
{
	c_p_c();
	return 0;
}