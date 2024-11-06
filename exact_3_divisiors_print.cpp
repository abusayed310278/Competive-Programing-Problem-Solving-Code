#include<bits/stdc++.h>
using namespace std;

void print3DivNums(int n) {

	int sq = sqrt(n);
	vector<bool>isPrime(sq + 1, true);

	for (int i = 2; i <= sq; i++) {

		if (isPrime[i]) {

			cout << i*i << " ";
			
			for (int j = i * i; j <= sq; j+=i) {
				isPrime[j] = false;
			}
		}
	}

}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);


	int n; cin >> n;
	print3DivNums(n);

	return 0;
}


