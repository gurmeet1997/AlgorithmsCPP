#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int countPairs(vector<int> &vec,int mid){
    int count=0;
    int j;
    for(int i=1,j=0;i<vec.size();i++){
        while(j<i&& (vec[i]-vec[j])>mid)
          j++;
        count+=i-j;
    }
    return count;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ll test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        } 
       int k;
       cin>>k;
       sort(vec.begin(),vec.end());
       int low=0,high=vec[n-1]-vec[0];
       while(low<high){
           int mid=(low+high)>>1;
           if(countPairs(vec,mid)>=k)
             high=mid;
           else
            low=mid+1;
       }
       cout<<low<<"\n";
        
        
    }
    return 0;
}