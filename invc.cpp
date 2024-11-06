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
vector<int> fn;

void update(int i, int val)
{
    i++;
    while (i < fn.size())
    {

        fn[i] += val;
        i += (i) & (-i);
    }
}

int getsum(int i)
{
    i++;
    int sum = 0;
    while (i > 0)
    {
        sum += fn[i];
        i -= (i) & (-i);
    }
}

void solve()
{

    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i].first = x;
        a[i].second = i;
    }

    fn.resize(n + 10);
    int ans = 0, b[n];
    sort(a, a + n);

    for (int i = 0; i < n; i++)
    {

        int ele = a[i].first;
        int index = a[i].second;

        b[i] = getsum(index + 1);
        
        ans += b[i];
        update(index, 1);

        
    }



    cout << ans << endl;

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