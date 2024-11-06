#include<bits/stdc++.h>
using namespace std;


//for sum using mo's algorithms: striver

int m;
bool cmp(pair<pair<int, int>, int >> p1, pair<pair<int, int>, int > p2) {

	int block_no1 = p1.first.first / m;
	int block_no2 = p2.first.first / m;

	if (block_no1 < block_no2)return true;
	if (block_no1 == block_no2) {
		if (p1.first.second <= p2.first.second)return true;
	}


	return false;
}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n; cin >> n; int a[n];
	for (int i = 0; i < n; i++)cin >> a[i];

	m = sqrt(n);

	int q; cin >> q;
	vector<pair<pair<int, int>, int >> p;
	for (int i = 0; i < q; i++) {
		int l, r; cin > l >> r;
		p.push_back({{l, r}, i});
	}

	sort(p.begin(), p.end(), cmp);
	int queryAns[q];
	int left = 0, right = 0;
	int sum = a[0];

	for (auto &it : p) {
		int l = it.first.first;
		int r = it.first.second;
		int queryNo = it.second;

		while (left < l) {
			sum -= a[left];
			left++;
		}

		while (left >= l) {
			left--;
			sum += a[left];
		}

		while (right <= r) {
			right++;
			sum += a[right];
		}

		while (right > r) {
			sum -= a[right];
			right--;
		}

		queryAns[queryNo] = sum;
	}

	for (int i = 0; i < q; i++)cout << queryAns[i] << endl;

	return 0;
}


/*

5 5
1 5 2 3 4
0 2 5
1 1 5 6
0 2 2
1 2 5 3
0 1 3

*/