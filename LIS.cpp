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

void LIS(vector<int> &vec,int n){
    if(vec.size()==0)
     return;
    vector<int> tail;
  tail.push_back(vec[0]);
    //int length=1;  //always points to next empty location in tail
    for(int i=1;i<n;i++){
       if(vec[i]<tail[0]){
        tail[0]=vec[i];
       }
       if(vec[i]>tail[tail.size()-1]){
        tail.push_back(vec[i]);
       }
       if(vec[i]<tail[tail.size()-1]){
        auto itr=lower_bound(tail.begin(),tail.end(),vec[i]);
        *itr=vec[i];
       }
      
    }
     cout<<tail.size()<<"\n";
     for(auto &x:tail){
      cout<<x<<" ";
     }
     cout<<"\n";
    
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
        vector<int> vec;
        for(int i=0;i<n;i++){
            ll temp;
            cin>>temp;
            vec.push_back(temp);
        }
        //cout<<vec.size()<<"\n";
       LIS(vec,n);



  		}

  
  }


int32_t main()
{
	c_p_c();
	return 0;
}