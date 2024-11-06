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

vi v;

vi f(int n)
{
    vi ans(n);
    stack<int> st;
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() and v[i] > v[st.top()])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        ans[st.top()] = -1;
        st.pop();
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    auto ans = f(n);
    for (int i = 0; i < ans.size(); i++)
        cout << (ans[i] == -1 ? -1 : v[ans[i]]) << " ";
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