#include<bits/stdc++.h>
using namespace std;
/*
These Sieve Variations will help you Solve many Number Theory Questions | CP Course | EP 60
by luv
*/
const int N=1e5+10;
vector<int>divisiors[N];

void sieveAlgo(){

	for(int i=2;i<N;i++)
	{
		for(int j=i;j<N;j+=i)
		{
			divisiors[j].push_back(i);
		}
		
	}
	
	for(int i=1;i<10;i++){

		for(int val:divisiors[i]){
			cout<<val<<" ";
		
		}
		cout<<endl;
	}
}




int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);

	sieveAlgo();

	return 0;
}

/*
24

*/