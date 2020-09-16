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

int dp[101][101][2];
int solve(string str,int i,int j,bool istrue){
  if(i>j){
    return false;
  }
  if(i==j){
    if(istrue){
      dp[i][j][0]=1;
       return str[i]=='T';}
    else{
      dp[i][j][1]=0;
      return str[i]=='F';}
    }
  

   if(dp[i][j][0]!=-1){
      return dp[i][j][0];
   }
   else if(dp[i][j][1]!=-1){
    return dp[i][j][1];
   }
  int ans=0;
  for(int k=i+1;k<=j-1;k++){
    int lt,lf,rt,rf;
    if(dp[i][k-1][0]!=-1){
      lt=dp[i][k-1][0];
    }
    else{
      lt=solve(str,i,k-1,true);
    }
    if(dp[i][k-1][1]!=-1){
       lf=dp[i][k-1][1];
    }
    else{
      lf=solve(str,i,k-1,false);
    }
    if(dp[k+1][j][0]!=-1){
      rt=dp[k+1][j][0];
    }
    else{
      rt=solve(str,k+1,j,true);
    }
    if(dp[k+1][j][1]!=-1){
      rf=dp[k+1][j][1];
    }
    else{
      rf=solve(str,k+1,j,false);
    }
    
  if(str[k]=='&'){
    if(istrue){
      ans+=lt*rt;    
      ans=ans%1003;
    }
  
  else{
    ans+=lt*rf+lf*rt+lf*rf;
    ans=ans%1003;
  }
}


  if( str[k]=='|'){
    if(istrue){
      ans+=lt*rt+lt*rf+lf*rt;
      ans=ans%1003;
    }
    else{
      ans+=lf*rf;
      ans=ans%1003;
    }
  }

    if(str[k]=='^'){
      if(istrue){
        ans+=lt*rf+lf*rt;
        ans=ans%1003;
      }
      else{
        ans+=lt*rt+lf*rf;
        ans=ans%1003;
      }
    }
  }
  return dp[i][j][0]=ans%1003;


}


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
  w(test){
         ll n;
         cin>>n;
         string str;
         cin>>str;
         memset(dp,-1,sizeof(dp));
         int result=solve(str,0,n-1,true);
         cout<<result<<"\n";


      }

}


int32_t main()
{
	c_p_c();
	return 0;
}