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
    vector<int> a(11);
    for (int i = 0; i < 11; i++)
        cin >> a[i];

    int k;
    cin >> k;
    int n = (1 << 11);

    map<int, int> fre;
    for (int mask = 0; mask < n; mask++)
    {
        int b = __builtin_popcount(mask);
        if (b != k)
            continue;

        int score = 0;
        for (int i = 0; i < 11; i++)
        {
            if (mask & (1 << i))
                score += a[i];
        }
        fre[score]++;
    }

    int ans = 0;
    int maxi = 0;
    for (auto x : fre)
    {
        if (x.first > maxi)
        {
            maxi = x.first;
            ans = x.second;
        }
    }

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