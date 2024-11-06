#include<bits/stdc++.h>
using namespace std;

int maxLeft(int arr[],int left,int mid)
{
	int sum=0,maxS=arr[mid];

	for(int l=mid;l>=left;l--){
		sum+=arr[l];
		maxS=max(maxS,sum);
	}

	return maxS;

}

int maxRight(int arr[],int mid,int right)
{
	int sum=0,maxS=arr[mid+1];


	for(int r=mid+1;r<=right;r++){
		sum+=arr[r];
		maxS=max(maxS,sum);
	}
	return maxS;
}

int maxsumSubArray(int arr[],int left,int right)
{
	if(left==right)return arr[left];

	int mid=(left+right)/2;

	int ans=max(maxsumSubArray(arr,left,mid),maxsumSubArray(arr,mid+1,right));

	return max(ans,maxLeft(arr,left,mid)+maxRight(arr,mid,right));
}

int main()
{
	// int arr[]= {0,-2,1,-3,4,-1,2,1,-5,4}; 
	int arr[]= {0,5,-6,3,4,-2,3,-3};// answer= 8 
	int n=sizeof(arr)/sizeof(arr[0]);
	 // cout<<n;
	cout<<maxsumSubArray(arr,1,n-1)<<endl;

	return 0;
}