#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long int
#define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const ll mod = 1e9 + 7;

void solve()
{
    // Write your solution code here
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N = 1e6 + 2;
    vector<ll> pre(N);

    pre[1] = 1;
    for (ll k = 2; k < N; k++)
    {
        pre[k] = (pre[k - 1] % mod * k % mod) % mod;
    }
    
    int t = 1;
    cin >> t;
    while (t--)
    {

        ll n;
        cin >> n;

        cout << (pre[n + 1] - 1) % mod << endl;
    }

    return 0;
}