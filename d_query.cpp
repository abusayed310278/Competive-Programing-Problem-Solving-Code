#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
int a[N];
//d_query using by moore's algorithms

struct query {
	int l, r, id, block, ans;
	bool operator<(query p)const {
		return make_pair(this->block, r) < make_pair(p.block, p.r);
	}
} q[N];

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	//array input
	int n; cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	int m = sqrt(n);

	//query input
	int queries; cin >> queries;
	for (int i = 0; i < queries; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].l--, q[i].r--;
		q[i].id = i; q[i].block = q[i].l / m;
	}

	sort(q, q + queries);
	//query print
	// for (int i = 0; i < queries; i++) {
	// 	cout << q[i].id << " " << q[i].block << " " << q[i].l << " " << q[i].r << endl;
	// }

	


	return 0;
}