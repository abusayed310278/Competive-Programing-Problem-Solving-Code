#include<bits/stdc++.h>
using namespace std;

void subsetXORSum(vector<int>& nums) {

	int n = nums.size();
	int  ans = 0;

	for (int i = 0; i < (1 << n); i++) {
		int bit = 0,x=0;

		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				x = nums[j];
			}

		}
		while (x != 0) {
			bit ^= x % 10;
			x /= 10;
		}
		ans += bit;

	}
	cout << ans;

}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	vector<int> nums{5,1,6};
	subsetXORSum(nums);

	return 0;
}