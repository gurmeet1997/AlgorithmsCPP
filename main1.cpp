#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define ll long long int
int main(){
	     ll query[];

		ll n,count=1;
		cin>>n;
		vector<ll> arr(n);
		int check[MAX]={0};
	    int idx[MAX];
		for (int i = 0; i < n; ++i)
		{
			/* code */
			cin>>arr[i];
		}

      for(ll i=n-1;i<;i++){
       if(idx[arr[i]]==0){
       		idx[arr[i]]=count;
       		count++;
       	    check[arr[i]]=1
       }
       else{
       	idx[arr[i]]=count-1;
       }
      }

	
}
void heapify(int arr[],int n,int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[largest])
		 largest=l;
	if(r<n && arr[r]>arr[largest])
		 largest=r;
	if(largest!=i){
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	 }
}

void HeapSort(int arr[],int n){
	int startInd=n/2-1;
	for (int i=startInd;i>=0;i--)
	   heapify(arr,n,i);
	for(int i=n-1;i>=0;i--){
		swap(arr[0],arr[i]);
		heapify(arr,n,i);
	}
}
void Quicksort(int arr[],int low,int high){
	int pi;
	if(low<high){
		int pi=partition(arr,low,high);
		Quicksort(arr,low,pi-1);
		Quicksort(arr,pi+1,high);
	}
}
void InsertionSort(int arr[],int n){
	int i,j,key;
	for (int i = 1; i < n; ++i)	  //put the marker for unsorted part
								  //at 1th index and start iterating 
								  //till end of the array and at each point 
								 //if the current element is greater than key element
								  //then just shift it one position right and decrement j
								 //finally where the above condition fails just j++ and put the key

	{
		/* code */

      key=arr[i];
      j=i-1;
      while(j>=0&&arr[j]>key){
          
        arr[j+1]=arr[j];
        j=j-1;
      }
      arr[j+1]=key;
	}

}

int partition (int arr[], int low, int high)
{
    int pivot=arr[low];
    int i=low;
    for(int j=low+1;j<=high;j++){
        if(arr[j]<=pivot){			//j indicates larger element index
        	  						//so the terminating condition is 
        							//when arr[j]<=pivot then i++ and swap
        							//arr[i] and arr[j]
            i++;
            swap(arr[i],arr[j]);
        }
    }
   swap(arr[i],arr[low]);
   return i;
}
void Merge(int arr[],int l,int m,int r){
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L1[n1],L2[n2];
	for(i=0;<n1,i++)
		L1[i]=arr[i];
    for(j=0;j<n2,j++)
    	L2[j]=arr[j];
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2){
    	if(L1[i]<=L2[j]){
    		arr[k]=L1[i];
    		i++;
    	}
    	else{
    		arr[k]=L2[j];
    		j++;
    	}
    	k++;
    }
    while(i<n1){
    	arr[k]=L1[i];
    	i++;
    	k++;
    }
    while(j<n2){
    	arr[k]=L2[j];
    	j++;
    	k++;
    }

}
MergeSort(int arr[],int l,int h){
   if(l<h){
   	int mid=(l+h)/2;
   	MergeSort(arr,l,m);
   	MergeSort(arr,m+1,h);
   	Merge(arr,l,m,h);
   }
}
void SelectionSort(int arr[],int n){
	int i,j,minInd;
	for(i=0;i<n-1;i++){
		minInd=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[minInd]){
				minInd=j;
			}
		}
		swap(arr[i],arr[minInd]);
	}
}
void BubbleSort(int arr[],int n){   		//optimized BubbleSort
	bool swapped=false;
	for(int i=0;i<n-1;i++){
       swapped=false;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]arr[j+1]){
				 swap(arr[j],arr[j+1]);
				 swapped=true;
				}
		}
		if(swapped!=true)
			break;
	}
}

void CountSort(int arr[],int n){
	std::vector<int> v(arr,arr+n);
	int range=9;
	int count[range+1]={0};
	for (int i = 0; i < n; ++i)
	{
	    count[arr[i]]++;
	}
	for(int i=1;i<=range;i++){
		count[i]+=count[i-1];      //calculating cumulative
	}
    int output[n]={0};
    for(int i=0;i<n;i++){
    	if(arr[i]!=0){
    		output[count[arr[i]]-1]=arr[i];   //determining position in output
    		--count[arr[i]];
    	}
    }
    for(int i=0;i<n;i++){
    	arr[i]=output[i];
    }

}
int maxNum(int arr[],int n){
	int m=INT_MIN;
	for(int i=0;i<n;i++){
	    if(arr[i]>m){
	    	m=arr[i];
	    }
	}
	return m;
}

void CountForRadix(int arr[],int n,int exp){
	std::vector<int> v(arr,arr+n);
	int range=9;
	int count[range+1]={0};
	for (int i = 0; i < n; ++i)
	{
	    count[(arr[i]/n)%10]++;
	}
	for(int i=1;i<=range;i++){
		count[i]+=count[i-1];      //calculating cumulative
	}
    int output[n]={0};
    for(int i=0;i<n;i++){
    	if(arr[i]!=0){
    		output[(count[arr[i]]/exp)%10-1]=arr[i];   //determining position in output
    		--count[(arr[i]/exp)%10];
    	}
    }
    for(int i=0;i<n;i++){
    	arr[i]=output[i];
    }
}
void RadixSort(int arr[],int n){
  int mnum=maxNum(arr,n);

  for(int exp=1;mnum/exp>0;exp*=10){
  	CountForRadix(arr,n,exp);
  }
}


void BucketSort(int arr[],int n){
	std::vector<int> vec[n];
	for(int i=0;i<n;i++){
		int ind=n*arr[i];
		vec[ind].push_back(arr[i]);
	}
	for(int i=0;i<n;i++){
		sort(vec[i].begin(),vec[i].end());
	}
	int index=0
	for(int i=0;i<n;i++){
		for(int j=0;j<vec[i].size();j++){
			arr[index++]=vec[i][j];
		}
	}

}

//pigeonhall sorting is applied when the array elements are almost close to each
//other


void pigeonhall(int arr[],int n){
	int max=arr[0],min=ar[0];
	for(int i=0;i<n;i++){
		if(arr[i]>max)
			max=arr[i];
	    if(arr[i]<min)
	    	min=arr[i];
	}
	int range=max-min+1;
	vector<int> vec[range];
	for(int i=0;i<n;i++){
		int ind=arr[i]-min;
		vec[ind].push_back(arr[i]);
	}
	int index=0;
	for(int i=0;i<range;i++){
	for(auto it=vec[i].begin();it!=vec[i].end();it++){
		arr[index++]=*it;
	}

    }
}