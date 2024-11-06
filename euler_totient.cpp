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

    int cnt = n;
    for (int i = 2; i * i <= n; i++)
    {

        if (n % i == 0)
        {
            cnt = cnt - cnt / i;
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    if (n > 1)
    {
        cnt = cnt - cnt / n;
    }

    cout << cnt << endl;
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