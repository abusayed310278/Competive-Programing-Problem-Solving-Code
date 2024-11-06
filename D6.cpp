#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
#define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

void solve()
{

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    map<pair<int, int>, bool> m;

    	
	    for(int i=0;i<n;i++){
	        cin>>x[i]>>y[i];
	        m[{x[i],y[i]}]=true;
	    }
	    ll ans=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(i==j)continue;

	            int w=x[j]-x[i],h=y[j]-y[i];

	            pair<int,int>p1={x[i]+h,y[i]-w},p2={x[j]+h,y[j]-w};
                
	            if(m.find(p1)!=m.end() && m.find(p2)!=m.end()){
	                ans++;
	            }
	        }
	    }
	    cout<<ans/4<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}