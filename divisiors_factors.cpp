#include<bits/stdc++.h>
using namespace std;

/*
divisiors in programing by luv

*/

const long long int M=1e18+7;


//Tc:O(sqrt(n))
void divisiors(int n){

	int cnt=0;
	int sum=0;

	for(int i=1;i*i<=n;i++){

		if(n%i==0){
			cout<<i<<endl<<n/i<<endl;
			cnt+=1;
			sum+=i;
			if(n/i!=i){
				sum+=n/i;
				cnt+=1;
			}
			
		}
	}
	cout<<cnt<<" "<<sum<<endl;
}

int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);

	int n; 
	cin>>n;

	divisiors(n);
	return 0;
}

/*

50^64^32

*/