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
int flag1=0;
std::vector<int> path;
int flag2=0;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// bool comp(int a,int b){
//    if(a>0&&b<0)
//     return true;
//    if((a==0&&b<0)||(a>0&&b==0))
//     return true;
//    if((a>0&&b>0)||(a<0&&b<0)||(a<0&&b>0))
//     return false;
//    if((a==0&&b>0)||(a<0&&b==0))
//     return false;
// }

int dp[101];
int largest_fc(ll n){
    ll great=1;
    for(ll i=2;i<=n/2;i++)
    {
      if(n%i==0){
        great=i;
      }
    }
    return great;
}
bool is_prime(int number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;

}
void solutionf(ll f,ll s){
  //cout<<"hello"<<"\n";
  path.push_back(f);
  ll f1=dp[f];
  if(f1==s){
    flag2=1;
    path.push_back(s);
    return;
  }
  if(is_prime(f1)){
    path.push_back(f1);
    flag1=1;
    path.push_back(1);
   
    return;
  }
  solutionf(f1,s);



}
void solutions(ll s){
  path.push_back(s);
  ll s1=dp[s];
  if(is_prime(s1)){
    path.push_back(s1);
    if(flag1==0)
      path.push_back(1);
    return;
  }
  solutions(s1);

}

void c_p_c()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif
      ll m,n;
     
      cin>>m>>n;
      //cout<<m<<n<<"\n";
      dp[1]=1;
      dp[2]=1;
      dp[3]=1;
     for(ll i=4;i<=100;i++){
        dp[i]=largest_fc(i);
     }
      //cout<<dp[15689]<<"\n";
       ll mx=max(m,n);
       ll mn=min(m,n);
       solutionf(mx,mn);
       if(flag2==0){
       solutions(mn);}
     
      cout<<path.size()-1;
         
     //path.clear();
     //fill(dp,dp+20001,0);
   

}


int32_t main()
{
c_p_c();
return 0;
}