#include<bits/stdc++.h>
using namespace std;
/*
Binary exponentiation for large b number 

b<=10^18 or 

*/

const long long int M=1e18+7;

int binaryExp(int a,long long int b){

	int ans=1;
	while(b>0) //while(b){}
	{
		if(b&1){
			ans=(ans*1LL*a)%M;
		}
		a=(a*1LL*a)%M;
		b>>=1;
	}	

	return ans;
}

int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);

	int a,b; // a=division ,b=dividend
	cin>>a>>b;
	
	//cout<<powr(a,b);

	//a^b
	cout<<binaryExp(a,b)<<endl;

	return 0;
}

/*

2 5


*/