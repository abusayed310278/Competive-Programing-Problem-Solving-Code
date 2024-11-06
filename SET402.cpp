#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long

#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

bool valid(vector<long>&a, int n, long x, int h)
{

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= x)
            cnt++;
        else
        {
            if (a[i] % x == 0)
            {
                cnt += a[i] / x;
            }
            else
            {
                cnt += a[i] / x + 1;
            }
        }
    }

    return cnt > h;
}

void solve()
{
    // Write your solution code here
    long n, h;
    cin >> n >> h;
    vector<long> a(n);
    long x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        x += a[i];
    }

    long l = 1, hi = x;
    while (hi - l > 1)
    {

        long mid = (l + hi) / 2;
        if (valid(a, n, mid, h))
        {
            l = mid;
        }
        else
        {
            hi = mid;
        }
    }

    cout << hi << endl;
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