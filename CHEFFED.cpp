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

int sum(int n)
{

    int res = 0;
    while (n > 0)
    {
        res+= (n % 10);
        n /= 10;
    }

    return res;
}

void solve()
{
    // Write your solution code here
    int n;
    cin >> n;
    int ans = 0;
    for (int i = max(0, n - 97); i <= n; i++)
    {
        if (i + sum(i) + sum(sum(i)) == n)
            ans++;
    }

    cout << ans << endl;

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