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
vector<int> block_min, block_max;
int Size;
vector<int> a;

int maxi(int l, int r)
{

    int ans = -1;
    int i = l;
    while (i <= r)
    {
        if (i % Size == 0 and i + Size - 1 <= r)
        {
            ans = max(ans, block_max[i / Size]);
            i += Size;
        }
        else
        {
            ans = max(ans, a[i]);
            i++;
        }
    }
    return ans;
}

int mini(int l, int r)
{

    int ans = 1e8;
    int i = l;
    while (i <= r)
    {
        if (i % Size == 0 and i + Size - 1 <= r)
        {
            ans = min(ans, block_min[i / Size]);
            i += Size;
        }
        else
        {
            ans = min(ans, a[i]);
            i++;
        }
    }

    return ans;
}

void solve()
{
    // Write your solution code here
    int n;
    cin >> n;
    a.resize(n);
    Size = sqrt(n) + 1;
    // const int N=1e8;
    block_max.resize(Size, -1), block_min.resize(Size, INT_MAX);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        block_min[i / Size] = min(a[i], block_min[i / Size]);
        block_max[i / Size] = max(a[i], block_max[i / Size]);
    }

    int q;
    cin >> q;
    while (q--)
    {

        int l, r;
        cin >> l >> r;

        double min_in_range = mini(l, r);
        double max_in_range = maxi(l, r);

        double max_out_left = 0;
        if (l - 1 >= 0)
            max_out_left = maxi(0, l - 1);
        double max_out_right = 0;
        if (r + 1 < n)
            max_out_right = maxi(r + 1, n - 1);
        double max_out_range = max(max_out_left, max_out_right);

        double ans = min_in_range + max(max_out_range, (max_in_range - min_in_range) / 2.0);

        cout << fixed << setprecision(1) << ans << endl;
    }
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