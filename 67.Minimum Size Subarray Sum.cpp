/*#include<bits/stdc++.h>
using namespace std;

void Sum() {

	vector<int> arr{10, 20, 10, 5, 15};

	vector<int>prefixSum;

	prefixSum[0] = arr[0];

	for (int i = 1; i < arr.size(); i++) {
		prefixSum[i] = prefixSum[i - 1] + arr[i];
	}

	cout << prefixSum[0];

	for (int i = 0; i < 5; i++) {
		cout << prefixSum[i] << endl;
	}

}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	// Sum();

	vector<int> arr{10, 20, 10, 5, 15};

	vector<int>prefixSum;

	prefixSum[0] = arr[0];

	for (int i = 1; i < 5; i++) {
		prefixSum[i] = prefixSum[i - 1] + arr[i];
	}

	cout << prefixSum[0];

	for (int i = 0; i < 5; i++) {
		cout << prefixSum[i] << endl;
	}

	return 0;
}*/


#include <bits/stdc++.h>
using namespace std;

void fillPrefixSum(int arr[], int n, int target)
{
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j <= i; j++) {
			sum += arr[j];
			if (sum == target) {
				cout << "yes " << i << endl;
			}
		}
	}
}

// Driver Code
int main()
{
	int arr[] = { 10, 4, 16, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	fillPrefixSum(arr, n, 16);

}