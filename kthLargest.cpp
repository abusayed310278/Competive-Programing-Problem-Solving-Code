#include<bits/stdc++.h>
using namespace std;

int findKthLargetElement(vector<int>&a, int k) {

	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < a.size(); i++) {

		if (pq.size() < k) {
			pq.push(a[i]);
		} else if (pq.top() < a[i]) {
			pq.pop();
			pq.push(a[i]);
		}
	}
	return pq.top();
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n, k; cin >> n >> k;
	vector<int>a;
	while (n--) {
		int x; cin >> x;
		a.push_back(x);
	}

	cout << findKthLargetElement(a, k);

	return 0;
}