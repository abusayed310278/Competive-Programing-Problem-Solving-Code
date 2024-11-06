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
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][1];
    }

    sort(begin(v), end(v), [](auto a, auto b)
         {
        if(a[0]+a[1]==b[0]+b[1])return a[0]>b[0];
        return a[0]+a[1]<b[0]+b[1]; });

    int ans = 0, cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += v[i][0] + v[i][1];
        if (cur <= k)
            continue;
        ans = i;

        int min1 = INT_MAX, min2 = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (v[j][0] + v[j][1] <= v[i][0] + v[i][1])
                min1 = min(min1, cur - v[j][1]);
        }
        if (min1 <= k)
            ans = i + 1;

        cur -= v[i][0] + v[i][1];
        for (int j = i; j < n; j++)
        {
            min2 = min(min2, cur + v[j][0]);
        }
        cur += v[i][0] + v[i][1];
        if (min2 <= k)
            ans = i + 1;

        break;
    }

    if (cur <= k)
        ans = n;
    cout << ans << endl;
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