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
vector<int> fn;

void update(int i, int val)
{

    while (i <=fn.size())
    {

        fn[i] = max(fn[i], val);
        i += (i) & (-i);
    }
}

int query(int i)
{

    int maxi = 0;
    while (i > 0)
    {

        maxi = max(maxi, fn[i]);
        i -= (i) & (-i);
    }
    return maxi;
}

void solve()
{

    int n;
    cin >> n;
    fn.resize(n + 1);
    vector<int> a(n);
    
    for (int i=1;i<=n;i++){
        cin >>a[i];
        update(i,a[i]);

    }



    int q;
    cin >> q;
    while (q--)
    {

        int i;
        cin >> i;
        cout << query(i) << endl;

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}