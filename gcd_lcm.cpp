#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	int r;
	while(b%a!=0){
		r=b/a;
		b=a;
		a=b%a;
	}
	return r;
}

int main()
{
	#ifndef bitmask
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	

	int a,b;
	cin>>a>>b;
	//cout<<gcd(a,b)<<endl;	
	
	int lcm=(a*b)/gcd(a,b);	
	

	return 0;
}