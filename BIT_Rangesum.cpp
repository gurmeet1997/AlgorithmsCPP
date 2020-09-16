#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n;
int a[MAXN];
int BIT[MAXN];
//1 2 3 4 5 6 7 8
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
		update(i,a[i]);
	}
	int m;
	cin>>m;
	int x,vl,l,r;
	while(m--){
	 char ch;
	 cin>>ch;
	 //'U' is for update
	 // 'Q' is for Query
	 if(ch=='U'){
	 	cin>>x>>vl;
		 update(x,vl-a[x]);
		}
	else{
		cin>>l>>r;
	 	cout<<query(r)-query(l-1);
		}
	}
	return 0;
}