#include<bits/stdc++.h>
using namespace std;

/*
MMI=modular multiplicative inverse

*/
const int M=1e9+7;

int binaryExp(int a,long long b,int m){

	int ans=1;
	while(b>0) //while(b){}
	{
		if(b&1){
			ans=(ans*1LL*a)%m;
		}
		a=(a*1LL*a)%m;
		b>>=1;
	}	

	return ans;
}

int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);

	int a; 
	cin>>a;

	cout<<binaryExp(a,M-2,M)<<endl;

	

	return 0;
}

/*

50^64^32

*/