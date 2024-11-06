#include <bits/stdc++.h>
using namespace std;

//Tc: O(n^2)
void fillPrefixSum(int arr[], int n, int k)
{
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = i; j < i + k; j++) {
			sum += arr[j];
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}

//Tc: 
void slidingWindow(int nums[], int n, int k)
{
	int ans = INT_MIN, i = 0, j = 0 ,sum = 0;

	while (j < n) {
		
		sum += nums[j];

		if (j-i+1 < k) {
			++j;
		}
		else if (j - i + 1 == k) {
			ans = max(ans, sum);
			sum-=nums[i];
			i++; j++;
		}

	}
	cout << ans << endl;
}



// Driver Code
int main()
{
	int arr[] = {10, 4, 16, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	// fillPrefixSum(arr, n - 1, 2);
	slidingWindow(arr, n, 2);

}