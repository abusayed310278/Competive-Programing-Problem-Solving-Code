#include<bits/stdc++.h>
using namespace std;

/*
Binary exponentiation iterative method
for this code is run for this Constraint:

1<=a,b<=10^8

M=1e9+7

*/

const int M=1e9+7;


//iterative method,Tc=log(b)
int binaryExpIter(int a,int b){

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
	cout<<binaryExpIter(a,b)<<endl;

	return 0;
}

/*

2 5


*/