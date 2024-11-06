/*

space optimised version of sieve of erastothenes
more space=more range of prime numbers you can store.

*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N=1e7;
bitset<N+5>b;
vector<int>p;

void sieve(){

	b.set();//1,1,1,---
	b[0]=b[1]=0;

	for(ll i=2;i<=N;i++){
		
		if(b[i]==1){
			p.push_back(i);
			for(ll j=i*i;j<=N;j+=i){
				b[j]=0;
			}
			
		}
	}
}

int main()
{
	#ifndef bitset
		//freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	sieve();
	for(int i=0;i<=10;i++){
		cout<<p[i]<<endl;
	}
	return 0;
} 

/*

all(),count(),none(),flip(),set(),rest(),hash(),string(),test(),ullong()	
any(),
*/