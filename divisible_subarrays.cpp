#include<bits/stdc++.h>
#define ll long 
#define endl "\n"
using namespace std;

const int N = 1e6+5;
ll pf[N], a[N];

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);


	int t; cin >> t;

	while (t--) {
		int n; cin >> n;
		memset(pf, 0, sizeof(pf));


		pf[0] = 1;
		int sum=0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			sum+=a[i];
			sum%=n;
			sum=(sum+n)%n;
			pf[sum]++;
		}

		ll ans=0;
		for(int i=0;i<n;i++){
			int m=pf[i];
			ans+=m*(m-1)/2;
		}
		cout<<ans<<endl;
	}

	

	return 0;
}


/*

1
5
1 3 2 4 6
5
5 5 5 5 5


*/