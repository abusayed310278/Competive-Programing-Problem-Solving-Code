#include <bits/stdc++.h>
using namespace std;

//Tc:
void slidingWindow(int nums[], int n, int target)
{
	int ans = INT_MIN, i = 0, j = 0 ;
	long sum = 0;

	while (j < n) {

		sum += nums[j];

		if (sum < target) {
			++j;
		}
		else if (sum == target) {
			ans = max(ans, j - i + 1);
			j++;
		} else if (sum > target) {
			
			while (sum > target) {
				sum -= nums[i];
				i++;
			}
			j++;
		}

	}
	cout << ans << endl;
}



// Driver Code
int main()
{
	int arr[] = {4, 1, 1, 1, 2, 3, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	// fillPrefixSum(arr, n - 1, 2);
	slidingWindow(arr, n, 5);

}