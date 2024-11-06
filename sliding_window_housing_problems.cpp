#include<bits/stdc++.h>
using namespace std;

void housing(int *arr,int n,int k){
	int i=0,j=0,cs=0;
	
	while(j<n){
		cs+=arr[j];j++;

		while(cs >k and i<j){
			cs-=arr[i];i++;
		}
		if(cs==k){
			cout<<i<<"->"<<j-1<<endl;
		}

	}
}


int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;cin>>n;
	int k;cin>>k;
	int plots[n];
	memset(plots,0,sizeof(plots));

	for(int i=0;i<n;i++){
		int x;cin>>x;
		plots[i]=x;
	}
	housing(plots,n,k);
	return 0;
}