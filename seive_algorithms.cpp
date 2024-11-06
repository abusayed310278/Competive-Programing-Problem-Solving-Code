#include<bits/stdc++.h>
using namespace std;
/*
Sieve Algorithm: How to find Prime Numbers Optimally ? | CP Course | EP 59
by luv
*/
const int N=1e7+10;
vector<bool>isPrime(N,1);

void sieveAlgo(){
	isPrime[0]=isPrime[1]=false;

	for(int i=2;i<N;i++){
		if(isPrime[i]==true){
			for(int j=2*i;j<N;j+=i){
				isPrime[j]=false;
			}
		}
	}

	/*for(int i=1;i<10;i++){
		cout<<isPrime[i]<<endl;
	}*/

	//for query, Tc:O(1)
	int q;
	cin>>q;
	while(q--){
		int num;
		cin>>num;
		if(isPrime[num]){
			cout<<"prime"<<endl;
		}else{
			cout<<"not prime"<<endl;
		}
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

5 
4
17 
19
21
23




*/