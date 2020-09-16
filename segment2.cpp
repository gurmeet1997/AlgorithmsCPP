/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
/*
// Sample code to perform I/O:
#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here




Query 0:- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.





#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAXN 100001
int arr[MAXN];
pair<int,int> st[4*MAXN];   //odd,even
void build(int si,int ss,int se){
	if(ss==se){
		if(arr[ss]%2==0){
			st[si]={0,1};
		}
		else
		  st[si]={1,0};
		return;
	}
	ll mid=(ss+se)/2;
	build(2*si,ss,mid);
	build(2*si+1,mid+1,se);

	st[si].first=st[2*si].first+st[2*si+1].first;
	st[si].second=st[2*si].second+st[2*si+1].second;
}
void pointUpdate(int si,int ss,int se,int qi,int newvalue){
	if(ss==se){
		if(arr[ss]%2==1){
			st[si]={0,1};
		}
		else{
			st[si]={1,0};
		}
        arr[qi]=newvalue;
		return;
	}
  int mid=(ss+se)/2;
  if(qi<=mid)
    pointUpdate(2*si,ss,mid,qi,newvalue);
  else
    pointUpdate(2*si+1,mid+1,se,qi,newvalue);
  

  st[si].first=st[2*si].first+st[2*si+1].first;
  st[si].second=st[2*si].second+st[2*si+1].second;




}
int getEven(int si,int ss,int se,int qs,int qe){
	if(se<qs||ss>qe)
	  return 0;
	if(ss>=qs && se<=qe)
	  return st[si].second;
	int mid=(ss+se)/2;
	int l=getEven(2*si,ss,mid,qs,qe);
     int r=getEven(2*si+1,mid+1,se,qs,qe);
	return l+r;
}


int getOdd(int si,int ss,int se,int qs,int qe){
	if(se<qs||ss>qe)
	  return 0;
	if(ss>=qs && se<=qe)
	  return st[si].first;
	int mid=(ss+se)/2;
	int l=getOdd(2*si,ss,mid,qs,qe);
     int r=getOdd(2*si+1,mid+1,se,qs,qe);
	return l+r;
}
int main(){
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>arr[i];
	
	build(1,1,n);
    int q;
	cin>>q;
	while(q--){
		int code;
		cin>>code;
		if(code==0){
		int l,r;
		cin>>l>>r;
        if(arr[l]%2==r%2)continue;
		else 
		  pointUpdate(1,1,n,l,r);
		}
		else{
		 if(code==1){
			 int l,r;
			 cin>>l>>r;
			 cout<<getEven(1,1,n,l,r)<<"\n";
		 }
		 else{
           int l,r;
		   cin>>l>>r;
		   cout<<getOdd(1,1,n,l,r)<<"\n";
		   }
		 }
	}
	
	
}