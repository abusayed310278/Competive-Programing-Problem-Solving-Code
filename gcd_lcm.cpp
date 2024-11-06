#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int gcd(int a,int b){

	if(b%a==0)
		return a;

	gcd(b%a,a);
}

int gcdCal(int a,int b){

	if(a==0)
		return b;

	gcd(b%a,a);
}



int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);

	int a,b; // a=division ,b=dividend
	cin>>a>>b;
	
	if(a>b)swap(a,b);	


	int g=gcd(a,b);
	cout<<g<<endl;
	cout<<(a*b)/g<<endl;


	return 0;
}

/*



*/