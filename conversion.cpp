#include<bits/stdc++.h>
using namespace std;

const int N=100;

char grid[N];

int main()
{
	freopen("in1.txt","r",stdin);
	freopen("out.txt","w",stdout);

	char ch;
	int t;cin>>t;
	int x=t;
	int i=0;
	while(t--){
		cin>>ch;
		grid[i]=ch;
		i++;
	}
	i=0;
	
	while(x--){

		if(grid[i]=='.')
			cout<<grid[i]<<endl;
		else
			cout<<grid[i]-'0'<<endl;
		i++;
	}


	
	return 0;
}