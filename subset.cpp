#include<bits/stdc++.h>
using namespace std;


int main()
{
	#ifndef bitmask
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	string s="abc";
	int n=s.size();


	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if( (i>>j &1) )
			cout<<s[j];
		}
		cout<<endl;
	}	
		
	

	return 0;
}