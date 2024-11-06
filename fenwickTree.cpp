#include<bits/stdc++.h>

using namespace std;

//amal paul
struct fenwick {
	vector<int>fn;
	int n;
	void init(int n) {
		this->n = n + 1;
		fn.resize(this->n, 0);
	}
	//building tree
	void add(int x, int y) {
		x++;//1 based index
		while (x < n) {
			fn[x] += y;
			x += (x & (-x)); //last set bit
		}
	}

	/*void add(int x,int y){
		for(x++; x<n; x+=(x&(-x)))fn[x]+=y;
	}*/

	//query
	int sum(int x) {
		x++;//1 based index
		int ans = 0;
		while (x) {
			ans += fn[x];
			x -= (x & (-x)); //last set bit
		}
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

};


int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	vector<int>v = {1, 2, 3, 4, 5, 6, 7};
	fenwick tree;
	tree.init(v.size());

	for (int i = 0; i < v.size(); i++) {
		tree.add(i, v[i]);
	}

	tree.add(4,-3);
	cout << tree.sum(3, 4) < endl;

	return 0;
}


/*




*/