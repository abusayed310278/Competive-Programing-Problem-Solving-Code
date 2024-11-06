#include <bits/stdc++.h>
using namespace std;

//Tc:
void slidingWindow(int nums[], int n, int k)
{
	int i = 0, j = 0 , sum = 0;
	list<int>l;
	vector<int>ans;

	while (j < n) {

		if (nums[j] < 0)
			l.push_back(nums[j]);

		if (j - i + 1 < k) {
			++j;
		}
		else if (j - i + 1 == k) {

			if (l.size() == 0)
				l.push_back(0);
			else {

				ans.push_back(l.front());

				if (nums[i] == l.front())
					l.pop_front();
				i++; j++;
			}
		}

	}
	for (auto x : ans) {
		cout << x << " ";
	}
}



// Driver Code
int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int arr[] = { 12, -1, -7, 8, -15, 30, 16, 28};
	int n = sizeof(arr) / sizeof(arr[0]);

	slidingWindow(arr, n, 3);

}