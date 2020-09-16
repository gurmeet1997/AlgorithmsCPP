#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n;
int a[MAXN];
int BIT[MAXN];
void update(int i,int val){
	for(;i<=n;i+= i&-i)
		BIT[i]+=val;
}
long long query(int i){
	long long sum=0;
	for(;i>0;i-= i&-i)
		sum+=BIT[i];
	return sum;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(a[i],1);
	}
	// Count BIT array is formed
	 // if you want to delete any element than call update(a[i],-1).
	int m;
	cin>>m;
	while(m--){
	 	int j;
	 	cin>>j;
	 	// returns the count of values less than or equal to a[j].
	 	cout<<query(a[j]);
	}
	return 0;
}