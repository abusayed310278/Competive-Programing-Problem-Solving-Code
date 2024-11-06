#include<bits/stdc++.h>
using namespace std;
/*
	GeeksForGeeks solution.
*/

#define bitsize 10

void bitSet(int n, int k) {

	if ((n & (1 << (k - 1))) != 0 )
		cout << "yes" ;
	else
		cout << "no";
}

void countBits(int n) {

	int ans = 0;
	while (n > 0) {
		n = n & (n - 1);
		ans++;
	}
	cout << ans << endl;
}

void findOddOccurance() {

	// vector<int>val{1,5,3,2};
	vector<int>val{1, 4, 3};
	int ans = 0;
	for (int i = 0; i < val.size(); i++) {

		ans ^= val[i];
	}
	cout << ans << endl;
}

void missingNumber() {

	// vector<int>val{1,5,3,2};
	vector<int>val{1, 4, 3};

	int miss_num = 0, n = val.size();
	for (int i = 1; i <= n + 1; i++) {

		miss_num ^=  i ^ val[i];

	}
	cout << miss_num << endl;
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	/*bitSet(5, 1); cout << endl;
	bitSet(5, 2);*/

	// countBits(5);

	findOddOccurance();
	// missingNumber();

	return 0;
}