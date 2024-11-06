#include<bits/stdc++.h>
using namespace std;

#define bitsize 10

void updateSum(vector<int>& sumArr, int x) {
	int cnt = 0;
	for (int i = 0; i < 32; i++) {
		int ith_bit = x & (1 << i);
		if (ith_bit) {
			sumArr[i]++;
		}
	}
}

int numFromBits(vector<int>& sumArr) {
	int num = 0;
	for (int i = 0; i < 32; i++) {
		num += sumArr[i] * (1 << i);
	}
	return num;
}

int uniqueNo3(vector<int>& arr) {

	vector<int>sumArr(32, 0);
	for (auto x : arr) {
		updateSum(sumArr, x);
	}

	for (int i = 0; i < 32; i++) {
		sumArr[i] %= 3;
	}

	return numFromBits(sumArr);
}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	vector<int>arr = {1, 3, 5, 4, 3, 1, 5, 5, 3, 1};
	cout << uniqueNo3(arr) << endl;
	return 0;
}



class Solution {
public:
	int subsetXORSum(vector<int>& nums) {

		int n = nums.size();
		int  ans = 0, XOR = 0;
		for (int i = 0; i < (1 << n); i++) {
			for (int j = 0; j < n; j++) {
				if ((i > j) & 1) {
					int XOR ^= nums[j];
				}
			}
			ans += nums[j];
		}
		return ans;

	}
};





