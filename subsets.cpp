#include<bits/stdc++.h>
using namespace std;


vector<string>v;
int main()
{
	#ifndef subsets
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	string s="235";
	int n=s.size();

	for(int i=0;i< (1<<n);i++){
		for(int j=0;j<n;j++){
			if((i>>j)&1)
				cout<<s[j];

		}
		cout<<endl;
	}	
		
		
	return 0;
}