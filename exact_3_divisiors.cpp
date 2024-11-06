#include<bits/stdc++.h>
using namespace std;

//better solution
void Ex3Divisiors(int n){

	for(int i=2;i*i<=n; i++){

		if(i==2)cout<<i*i<<" ";
		if(i%2!=0)cout<<i*i<<" ";
		
	}
}


bool isPerfectSqrt(int i){

	return (sqrt(i)-(int)sqrt(i))==0;
}

bool isPrime(int n) {

	if (n == 1)return false;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}

void Exact3Divisiors(int n){

	for(int i=2;i*i<=n; i++){

		if(isPerfectSqrt(i) and isPrime((int)sqrt(i)))cout<<i<<" ";
	}
}


int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);


	int n; cin >> n;
	Exact3Divisiors(n);

	return 0;
}


