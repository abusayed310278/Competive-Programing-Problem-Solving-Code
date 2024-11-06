#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
#define ll long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

int f(int x)
{
    return (x - 1) % 9 + 1;
}

void solve()
{
    // Write your solution code here
    int a, d, l, r;
    cin >> a >> d >> l >> r;
    l--,r--;
    int sum = 0;

    for (int i = 1; i < 10; i++)
    {
        sum += f(a + i * d);
    }

    int ans = 0;
    while ((r - l + 1) % 9 != 0)
    {
        ans += f(a + d * r);
        r--;
    }

    ans += sum * (r - l + 1) / 9;

    cout << ans << endl;
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