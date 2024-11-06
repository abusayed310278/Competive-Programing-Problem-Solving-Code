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

long gcd(long a, long b)
{

    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void solve()
{

    int n, k;
    cin >> n >> k;

    long long g = gcd(n, k);

    g = n / g;

    cout << g << endl;
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