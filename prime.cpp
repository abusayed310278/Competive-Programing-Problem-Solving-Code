#include<bits/stdc++.h>
using namespace std;

//tc: O(n)
bool f(int n) {
	if (n == 1)return false;

	for (int i = 2; i < n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}

//tc: O(sqrt(n))
bool prime(int n) {

	if (n == 1)return false;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}

//tc: O()

bool isPrime(int n) {

	if (n == 1)return false;
	if (n == 2 || n  == 3)return true;
	if (n % 2 == 0 || n % 3 == 0)return false;

	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0)return false;
	}
	return true;

}

//simple seive
void seive(int n) {

	vector<bool>isPrime(n + 1, true);//input as n=9
	for (int i = 2; i * i <= n; i++) {

		if (isPrime[i]) {
			for (int j = 2 * i; j <= n; j = j + i) {
				isPrime[j] = false;
			}
		}
	}


	//print
	for (int i = 2; i <= n; i++) {
		// cout << i<<": "<<isPrime[i] <<endl;
		if (isPrime[i])cout << i << " ";
	}
}

//more efficient,tc:
void seiveTh(int n) {

	vector<bool>isPrime(n + 1, true);
	for (int i = 2; i * i <= n; i++) {

		if (isPrime[i]) {
			for (int j = i * i; j <= n; j = j + i) {
				isPrime[j] = false;
			}
		}
	}


	//print
	for (int i = 2; i <= n; i++) {
		// cout << i<<": "<<isPrime[i] <<endl;
		if (isPrime[i])cout << i << " ";
	}
}

//shorter seive ,tc:O(nlog(log(n))) 
void seiveSH(int n) {

	vector<bool>isPrime(n + 1, true);
	for (int i = 2; i <= n; i++) {

		if (isPrime[i]) {

			cout << i << " ";
			for (int j = i * i; j <= n; j = j + i) {
				isPrime[j] = false;
			}
		}
	}

}

void Seive(int n) {

	vector<bool>isPrime(n + 1, true);
	for (int i = 2; i <= n; i++) {

		if (isPrime[i]) {

			for (int j = i * i; j <= n; j = j + i) {
				isPrime[j] = false;
			}
		}
	}

}


//segmented seive

void seiveSegmented(int l,int h){

	long long sq=sqrt(h);
	Seive(sq);
	vector<bool>isPrime(h-l+1,true);
	


	for(int i=l;i<=h;i++){
		if(isPrime[i])cout<<i<<" ";
	}

}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	/*int t; cin >> t;
	while (t--) {

		int n; cin >> n;

		if (isPrime(n))cout << "prime" << endl;
		else cout << "Not prime" << endl;
	}*/
	int n; cin >> n;
	// seive(n);
	// seiveTh(n);
	// seiveSH(n);
	
	int l,h;cin>>l>>h;
	seiveSegmented(l,h);

	return 0;
}


/* for first 3 function input

4
2
1
4
5

*/