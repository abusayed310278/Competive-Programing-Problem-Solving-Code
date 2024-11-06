#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	
	if(a%b==0)return b; //if(b==0)return a;
		return gcd(b,a%b);
}

int main()
{
	#ifndef bitmask
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif	

	int a,b;
	cin>>a>>b;
	int GCD=gcd(a,b);	
	cout<<"GCD: "<<GCD<<endl;	
	
	cout<<"LCM: "<<(a*b)/GCD;	
	cout<<endl<<__gcd(12,18)<<endl;//O(logn)
	

	return 0;
}