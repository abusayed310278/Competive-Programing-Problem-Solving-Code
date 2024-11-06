#include<bits/stdc++.h>
#define endl "\n"
#define int long long
#define ll long long
#define F  first
#define S  second
#define pb  push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

struct segmenttree {

	vector<int> st;
	int n;

	void init(int _n) {
		n = _n;
		st.clear();
		st.resize(4 * _n, 0);
	}

	void build(int l, int r, int node) {
		if (l == r) {
			// st[node] = a[l];
			return;
		}

		int mid = (l + r) / 2;
		build(l, mid, 2 * node + 1);
		build(mid + 1, r, 2 * node + 2);

		st[node] = max(st[2 * node + 1], st[2 * node + 2]);
	}

	void update(int s, int e, int indup, int val, int node) {

		if (indup > e || indup < s)return;

		if (s == e) {
			st[node] = val; return;
		}

		int mid = (s + e) / 2;

		update(s, mid, indup, val, 2 * node + 1);

		update(mid + 1, e, indup, val, 2 * node + 2);


		st[node] = max(st[2 * node + 1], st[2 * node + 2]);


		return;

	}

	int query(int s, int e, int l, int r, int node) {

		if ( l > e || s > r || l > r)return 0;

		if (s >= l && e <= r)return st[node];

		int mid = (s + e) / 2;
		int q1 = query(s, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, e, l, r, 2 * node + 2);

		return max(q1, q2);
	}

	void build(int n) {
		init(n);
		build(0, n - 1, 0);
	}

	int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int index, int val) {
		update(0, n - 1, index, val, 0);
	}



} tree;

void solve() {

	int n; cin >> n;
	int h[n], a[n], dp[n], idx[n];

	for (int i = 0; i < n; i++) {

		cin >> h[i];
		h[i]--;
		idx[h[i]] = i;

	}

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	tree.init(n);

	for (int i = 0; i < n; i++) {

		int index = idx[i];
		dp[index] = tree.query(0, index - 1) + a[index];
		tree.update(index, dp[index]);

	}

	cout << tree.query(0, n - 1)<<endl;


}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();

	}

	return 0;
}