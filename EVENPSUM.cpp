#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

void solve()
{
    int a, b;
    cin >> a >> b;

    int ae = a / 2;       
    int ao = a - ae;      
    int be = b / 2;       
    int bo = b - be;      

   
    ll ans = ((1LL * ae * be) % mod + (1LL * ao * bo % mod)) % mod;

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
