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
    int n, m;
    cin >> n >> m;

    int minc = m, maxc = -1, minr = n, maxr = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
            {

                if (j < minc)
                    minc = j;
                if (j > maxc)
                    maxc = j;

                if (i < minr)
                    minr = i;
                if (i > maxr)
                    maxr = i;
            }
            else
            {
                cnt++;
            }
        }
    }

    int ans1 = (maxc - minc + 1) / 2;
    int ans2 = (maxr - minr + 1) / 2;
    if (cnt == n * m)
        cout << 0 << endl;
    else
        cout << max(ans1, ans2) + 1 << endl;
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