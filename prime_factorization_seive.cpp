#include<bits/stdc++.h>
//#define long long ll; 
using namespace std;

const int N=1e6+10;
int p[N];

//naive approach O(sqrt(n)*n)
bool isPrime(int n){

	if(n==1)return false;
	if(n==2)return true;

	for(int i=2;i<n;i++){
		if(n%i==0)return false;

	}
	return true;
}

//naive approach O(sqrt(n)*n)
bool isPrimeBetterWay(int n){

	if(n==1)return false;
	if(n==2)return true;

	for(int i=2;i*i<n;i++){
		if(n%i==0)return false;

	}
	return true;
}

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
	
	int n,t;
	/*cin>>t;
	while(t--){
		cin>>n;
		cout<<isPrime(n)<<endl;	
	}*/
	cin>>n;
	prime_seive(p);
	for(int i=0;i<=n;i++){
		if(p[i]==1){
			cout<<i<<endl;
		}
	}	


	return 0;
}