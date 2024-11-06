#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
#define ll long long
#define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

vector<int> v;
void pre()
{

    for (int i = 0; i <= 1000; i++)
    {
        v.push_back((1 << i) % mod);
    }
}

void solve()
{
    // Write your solution code here
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
}

int32_t main()
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