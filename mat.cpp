#include<bits/stdc++.h>
using namespace std;




int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
	int n=5;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if( i==j || (i+j)==(n+1))cout<<"*";
			else cout<<" ";
		}
		cout<<endl;
	}	


	return 0;
}


/*

for query i/p:
3
4 4
0 4
0 1

0-based indexed array :
left=2*parent
right=2*parent+1

1-based indexed array:
left=2*parent+1
right=2*parent+2



*/