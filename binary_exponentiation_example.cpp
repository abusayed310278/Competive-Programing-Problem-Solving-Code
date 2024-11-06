#include<bits/stdc++.h>
using namespace std;

/*
Binary exponentiation for large b number 

50^64^32

*/

const long long int M=1e18+7;

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

	int a,b,c; 
	cin>>a>>b>>c;

	//a^b^c
	cout<<binaryExp(a,binaryExp(b,c,M-1),M)<<endl;

	return 0;
}

/*

50^64^32

*/