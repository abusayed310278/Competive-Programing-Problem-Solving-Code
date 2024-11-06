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
    int n;
    cin >> n;
    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    int ans = 0;
    while (!q.empty())
    {

        if (q.size() == 1)
        {
            ans += q.top();
            q.pop();
            continue;
        }

        auto a = q.top();
        q.pop();
        auto b = q.top();
        q.pop();

        auto mini = min(a, b);
        ans += mini;
        if (a == b)
            continue;
        a -= mini;

        q.push(a);
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