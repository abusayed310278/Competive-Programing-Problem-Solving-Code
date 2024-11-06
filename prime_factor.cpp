#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {

	if (n == 1)return false;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}

//O(n^2*log(n))
void primefactors(int n) {

	for (int i = 2; i < n; i++) {//O(n)

		if (isPrime(i)) {//O(n)
			int x = i;
			//O(log(n))
			while (n % x == 0) {
				cout << x << endl;
				x = x * i;
			}
		}
	}

}

void printPrimeFactors(int n) {

	if (n <= 1)return;
	for (int i = 2; i * i <= n; i++) {

		while (n % i == 0) {
			cout << i << endl;
			n /= i;
		}
	}
	if (n > 1)
		cout << n;

}


//more efficient solution,tc:O(sqrt(n))
void PrimeFactors(int n){

	if(n<=1)return;

	if(n%2==0){cout<<2<<" "; n/=2;}
	if(n%3==0){cout<<3<<" "; n/=3;}

	for(int i=5; i*i<=n; i+=6){

		while(n%i==0){cout<<i<<" ";n/=i;}
		while(n%(i+2)==0){cout<<i+2<<" ";n/=(i+2);}
	}

	if(n>3)cout<<n;
}



int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	/*int n; cin >> n;
	primefactors(n);*/

	int n; cin >> n;
	printPrimeFactors(n);

/*	int n;cin>>n;
	PrimeFactors(n);*/

	return 0;
}


