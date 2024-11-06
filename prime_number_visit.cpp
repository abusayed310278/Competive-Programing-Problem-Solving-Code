#include<bits/stdc++.h>
//#define long long ll; 
using namespace std;

const int N=1e6+10;
int p[N],csum[N];

//seive approach O(N*log log(N))
bool prime_seive(int *p){
	//special case
	p[0]=p[1]=0;
	p[2]=1;

	//odd number marked as prime
	for(int i=3;i<=N;i+=2){
		p[i]=1;
	}

	for(long long  i=3;i<=N;i+=2){
		if(p[i]==1){
			for(long long j=i*i;j<=N;j+=i){
				p[j]=0;
			}
		}
	}
	
}


int main()
{
	#ifndef subsets
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	
	prime_seive(p);

	for(int i=1;i<=N;i++){
		csum[i]=csum[i-1]+p[i];
	}

	int q;
	cin>>q;

	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<csum[b]-csum[a-1]<<endl;
	}	


	return 0;
}