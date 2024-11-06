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

struct Node
{
    int w, s, v;
    Node(int w, int s, int v) : w(w), s(s), v(v) {}
};

int n;
vector<Node> a;
int dp[1001][10*1001];

int f(int id, int wt)
{
    if (id == n or wt > 1000)
        return 0;

    int ans = dp[id][wt];
    if(ans!=-1)return ans;
    ans=0;
    ans = f(id + 1, wt);
    if (wt <= a[id].s)
    {
        ans = max(ans, a[id].v + f(id + 1, wt + a[id].w));
    }
    return ans;
}

bool cmp(Node &a, Node &b)
{
    return a.w + a.s < b.w + b.s;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a.push_back(Node(x, y, z));
    }

    sort(begin(a), end(a), cmp);
    memset(dp,-1,sizeof(dp));

    cout << f(0, 0) << endl;
}

int32_t main()
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