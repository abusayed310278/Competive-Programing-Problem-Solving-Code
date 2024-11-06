#include<bits/stdc++.h>
using namespace std;

int a[10000], BIT[10000] = {0};

//range max query
void update(int i, int val, int n) {
	while (i <= n) {
		BIT[i] += val;
		i += (i & (-i));
	}
}

//sum till the ith idex-log(n)
int query(int i) {
	int ans=0;
	while(i>=0){
		ans+=BIT[i];
		i-=(i&(-i));
	}
	return ans;
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
	int n; cin >> n;

	//build BIT Tree
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i, a[i], n);
	}

	//query
	int q;cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<query(r)-query(l-1)<<endl;
	}

	return 0;
}