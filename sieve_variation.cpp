#include<bits/stdc++.h>
using namespace std;
/*
These Sieve Variations will help you Solve many Number Theory Questions | CP Course | EP 60
by luv
*/
const int N=1e7+10;
vector<bool>isPrime(N,1);
vector<int>lp(N,0),hp(N,0);

void sieveAlgo(){
	isPrime[0]=isPrime[1]=false;

	for(int i=2;i<N;i++)
	{
		if(isPrime[i]==true)
		{
			lp[i]=hp[i]=i;
			for(int j=2*i;j<N;j+=i)
			{
				isPrime[j]=false;
				hp[j]=i;
				if(lp[j]==0){
					lp[j]=i;
				}
			}
		}
	}

	/*for(int i=1;i<10;i++){
		cout<<lp[i]<<" "<<hp[i]<<endl;
	}*/
	int num;cin>>num;
	vector<int>prime_factors;

	while(num>1){
		int prime_factor=hp[num]; //int prime_factor=lp[num];
		while(num%prime_factor==0){
			num/=prime_factor;
			prime_factors.push_back(prime_factor);
		}
	}

	for(int prime:prime_factors){
		cout<<prime<<" ";
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