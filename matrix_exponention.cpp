#include<bits/stdc++.h>
using namespace std;

int powr(int a,int b){
	
	int res=1;
	
	while(b)
	{
		if(b&1)res*=a;

		a*=a;
		b/=2;
		//b=b>>1;
	}
	return res;
}

int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);


	cout<<powr(2,10)<<endl;

	return 0;
}