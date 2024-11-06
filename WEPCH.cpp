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
    // Write your solution code here
    int h, x, y1, y2, k;
    cin >> h >> x >> y1 >> y2 >> k;
    int cnt = 0, xx = 0, yy = 0;

    xx = ceil(h / x);

    if (h % y1)
    {
        int i;
        for (i = 1; i <= k; i++)
        {
            if (yy + i * y1 >= h)
                break;
            yy += y1;
            cnt++;
        }
        if (i == k and (h - yy) > 0)
        {
            cnt += ceil((h - yy) / y2);
        }
    }

    cout << min(cnt, xx) << endl;
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