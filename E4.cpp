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

    int a, b, c, p;
    cin >> a >> b >> c >> p;

    vector<int> ans;
    for (int w = 0; w < p; w += 1)
    {
        int area = a * w * w + b*w + c;
        if (area % p == 0)
        {
            ans.push_back(w);
        }
    }

    cout<<ans.size()<<" ";
    for (auto x : ans)
    {
        cout << x << " ";
    }

    ans.clear();
    cout << endl;
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