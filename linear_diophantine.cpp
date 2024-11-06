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
class Pair
{
public:
    long x, y, gcd;
    Pair(long x, long y, long gcd)
    {
        this->x = x;
        this->y = y;
        this->gcd = gcd;
    }
};

Pair euclids(long a, long b)
{

    if (b == 0)
        return Pair(1, 0, a);

    Pair cur = euclids(b, a % b);

    return Pair(cur.y, cur.x - (a / b) * cur.y, cur.gcd);
}

void solve()
{

    int a, b, k;
    cin >> a >> b >> k;
    Pair ans = euclids(a, b);

    ans.x *= k;
    ans.y *= k;

    cout << ans.x << " " << ans.y << endl;
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