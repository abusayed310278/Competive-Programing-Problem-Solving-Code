/*
-space optimised sieve using bitset
-checking if a large Number is prime or not such as: 10^12
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

bool isPrime(ll No){
	if(No<=N){
		return b[No]?true:false; 
	}

	for(ll i=0;p[i]*(long long)p[i]<=No;i++){
		if(No%p[i]==0){
			return false;
		}
	}

	return true;
}

int main()
{
	#ifndef bitset
		//freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	sieve();
	int n;cin>>n;
	if(isPrime(n)){
		cout<<"yes it is";
	}else{
		cout<<"No its not";
	}

	return 0;
} 

/*

all(),count(),none(),flip(),set(),rest(),hash(),string(),test(),ullong()	
any(),
*/