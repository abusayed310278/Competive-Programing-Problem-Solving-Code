#include<bits/stdc++.h>

using namespace std;

//pratek narang

int lazy[10000] = {0};
//minimum element find
void buildTree(int s, int e, int *a, int *tree, int ind) {

	if (s == e) {
		tree[ind] = a[s];
		return;
	}
	int mid = (s + e) / 2;
	buildTree(s, mid, a, tree, 2 * ind);
	buildTree(mid + 1, e, a, tree, 2 * ind + 1);

	tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
	return;
}

int query(int s, int e, int l, int r, int *tree, int ind) {

	if (lazy[ind] != 0) {
		tree[ind] += lazy[ind];

		if (s != e) {
			lazy[2 * ind] += lazy[ind];
			lazy[2 * ind + 1] += lazy[ind];
		}
		lazy[ind] = 0;
	}

	//no overlaping ,here l and r is query range
	if (s > r || e < l) {
		return INT_MAX;
	}

	//complete overlap
	if (s >= l and e <= r) {
		return tree[ind];
	}

	//partial overlap
	int mid = (s + e) / 2;
	int q1 = query(s, mid, l, r, tree, 2 * ind);
	int q2 = query(mid + 1, e, l, r, tree, 2 * ind + 1);

	return min(q1, q2);

}


// range update
void updateRange(int s, int e, int *tree, int value, int l, int r, int ind ) {

	//before going down resolve the value if it exists
	if (lazy[ind] != 0) {
		tree[ind] += lazy[ind];

		if (s != e) {
			lazy[2 * ind] += lazy[ind];
			lazy[2 * ind + 1] += lazy[ind];
		}
		lazy[ind] = 0;
	}

	// base case  //out of bound
	if (s > r ||  e < l )return;

	if (s >= l &&  e <= r) {
		tree[ind] += value;

		if (s != e) {
			lazy[2 * ind] += value;
			lazy[2 * ind + 1] += value;
		}
		return;
	}

	int mid = (s + e) / 2;

	// left subtree
	updateRange(s, mid, tree, value, l, r, 2 * ind);

	// right
	updateRange(mid + 1, e, tree, value, l, r, 2 * ind + 1);


	tree[ind] = min(tree[2 * ind ] , tree[2 * ind + 1]);

	return;
}

void show(int *tree) {

	for (int i = 1; i <= 13; i++)
		cout << tree[i] << " ";
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int a[] = {1, 3, 2, -5, 6, 4};
	int n = sizeof(a) / sizeof(int);

	int *tree = new int[4 * n + 1];
	buildTree(0, n - 1, a, tree, 1); // 1 based indexed tree


	//range update
	updateRange(0, n - 1, tree, +10, 5, 6 , 1); // means  idx=3 ,now update: tree[idx]=+10
	updateRange(0, n - 1, tree, +10, 0, 2, 1);
	updateRange(0, n - 1, tree, +10, 0, 4, 1);

	//query
	cout<<query(0, n - 1, 1, 1, tree, 1)<<endl;

	updateRange(0, n - 1, tree, +10, 3, 4, 1);
	cout<<query(0, n - 1, 3, 5, tree, 1)<<endl;

	// show(tree);



	return 0;
}


/*

for query i/p:
3
4 4
0 4
0 1

0-based indexed array :
left=2*parent
right=2*parent+1

1-based indexed array:
left=2*parent+1
right=2*parent+2



*/