#include<bits/stdc++.h>
using namespace std;

/*
Expected Head:
a fair coin is thrown N times,what is the expected number of heads.
*/

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);



	return 0;
}

/*class Solution {
public:
	string multiply(string num1, string num2) {

		if (num1 == "0" || num2 == "0")return "0";

		vector<int>num(num1.size() + num2.size());

		for (int i = num1.size() - 1; i > 0; i--) {
			for (int j = num2.size() - 1; j > 0; j--) {

				num[i + j + 1] += (num1[i] - '0') * (num2[i] - '0');
				num[i + j] += num[i + j + 1] / 10;
				num[i + j + 1] %= 10;
			}
		}

		int i = 0;
		while (i < num.size() && num[i] == 0)++i;

		string ans = "";

		while (i < num.size())ans.push_back(num[i++] + '0');

		return ans;
	}
};*/

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		vector<vector<int>>ans;

		int r = matrix.size() - 1;
		int c = matrix[0].size() - 1;

		for (int i = 0; i <= r; i++) {
			for (int j = r; j >= 0; j--) {
				ans[i].push_back(matrix[j][i]);
			}
		}
	}
};