#include <bits/stdc++.h>
#define endl "\n"
#define llt long long int
#define ll long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

llt gcd(llt a, llt b)
{

    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void solve()
{
    // Write your solution code here
    llt n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << (3 * n) / 2 << endl;
    }
    else
    {
        llt fc = 0, ans, i;
        for (i = 3; i <= sqrt(n); i += 2)
        {
            if (n % i == 0)
            {
                fc = n / i;
                break;
            }
        }
        if (fc != 0)
            ans = fc * (i + 1);
        else
            ans = n + 1;

        cout << ans << endl;
    }
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