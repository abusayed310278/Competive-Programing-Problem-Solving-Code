#include<bits/stdc++.h>
using namespace std;


int main()
{
	#ifndef bitmask
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	/*for(int i=0;i<15;i++){
		bitset<4>a(i);
		cout<<a<<endl;	
	}*/
	//cout<<(1<<2)<<endl;	

	int a,i;
	cin>>a>>i;
	cout<< (a | (1<<i));	
		
	

	return 0;
}