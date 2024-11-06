#include<bits/stdc++.h>
using namespace std;

/*
prime check and prime factorization in programing by luv

*/

const long long int M=1e18+7;

//Tc:O(n)
void primeCheck(int n){

	bool is_prime=true;

	if(n==1){
		is_prime=false;
	}

	for(int i=2;i<n;i++){
		if(n%i==0){
			is_prime=false;
			break;
		}
	}
	cout<<is_prime<<endl;
	
}

//Tc:O(n)
void primeFactorization(int n){

	vector<int>res;
	for(int i=2;i<=n;i++){
		
		while(n%i==0){
			res.push_back(i);
			n/=i;
		}
	}

	for(int val:res){
		cout<<val<<" ";
	}
	
}

//Tc:O(sqrt(n))
void primeFactorizationCal(int n){

	vector<int>res;
	for(int i=2;i*i<=n;i++){
		
		while(n%i==0){
			res.push_back(i);
			n/=i;
		}
	}

	if(n>1){
		res.push_back(n);
	}

	for(int val:res){
		cout<<val<<" ";
	}
	
}

int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);

	int n; 
	cin>>n;

	//primeCheck(n);
	//primeFactorization(n);
	primeFactorizationCal(n);

	return 0;
}

/*
24
36

*/