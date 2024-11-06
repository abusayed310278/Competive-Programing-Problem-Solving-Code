#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int n;cin>>n;
	int a[n+1];
	int ps[n+1];

	memset(a,0,sizeof(a));
	memset(ps,0,sizeof(ps));

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	ps[0]=a[0];
	for(int i=1;a[i]!=0;i++){
		ps[i]=ps[i-1]+a[i];
		
	}	

	for(int i=0;ps[i]!=0;i++){
		cout<<ps[i]<<" ";
	}



	return 0;
}