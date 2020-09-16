#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define MOD             1000000007
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


int partition(std::vector<int> vec,int n,int sum){
  int dp[n+1][sum+1];
  memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++){
      dp[i][0]=1;
    }

    for(int j=1;j<=sum;j++){
      dp[0][j]=0;
    }

    for(int i=1;i<=n;i++){
      for(int j=1;j<=sum;j++){
        if(vec[i-1]<=j){
          dp[i][j]=dp[i-1][j]||dp[i-1][j-vec[i-1]];
        }
        else{
          dp[i][j]=dp[i-1][j];
        }
      }
    }
   return dp[n][sum];
}


void c_p_c()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
  int test;
  cin>>test;
  while(test--){
    int n;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
      int temp;
      cin>>temp;
      vec.push_back(temp);
    }

    int presum=-0;
    for(int i=0;i<n;i++)
       presum+=vec[i];
    if(presum%2!=0)
       cout<<"NO"<<"\n";
     else{
      int result=partition(vec,n,presum/2);
      if(result)
        cout<<"YES"<<"\n";
      else
         cout<<"NO"<<"\n";
     }
    

  }
         
     
   

}


int32_t main()
{
c_p_c();
return 0;
}