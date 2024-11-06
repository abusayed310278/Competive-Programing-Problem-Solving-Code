#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
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
    int n;
    cin >> n;
    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    int i = 0, other = 0, chef = 0;
    while (!q.empty())
    {
        auto x = q.top();
        q.pop();
        if (i & 1)
        {
            other += x;
        }
        else
        {
            chef += x;
        }

        i++;
    }

    cout << chef << endl;
}

int32_t main()
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