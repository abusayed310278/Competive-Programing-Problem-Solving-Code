#include<bits/stdc++.h>
using namespace std;

vector<long long>prime;
//simple seive
void Seive(int n) {

	vector<bool>isPrime(n + 1, true);
	for (int i = 2; i <= n; i++) {

		if (isPrime[i]) {

			prime.push_back(i);

			for (int j = i * i; j <= n; j = j + i) {
				isPrime[j] = false;
			}
		}
	}

}

//segmented seive
void seiveSegmented(int l, int h) {

	long long sq = sqrt(h);
	Seive(sq);
	vector<bool>isPrime(h - l + 1, true);

	for (long long &p : prime) {

		long long sm = (l / p) * p;
		if (sm < l)sm += p;

		for (long long m = sm; m <= h; m = m + p) {
			isPrime[m - l] = false;
		}
	}


	for (long long m = l; m <= h; m++) {
		if (isPrime[m-l])cout << m<< " ";
	}

}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int l, h; cin >> l >> h;
	seiveSegmented(l, h);

	return 0;
}


/*

when we use segmented seive:
->n is very large(say n=1e9)
->we have range[l,h] as input ans h is very large


*/