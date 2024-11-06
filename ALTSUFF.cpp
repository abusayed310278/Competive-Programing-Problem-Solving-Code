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
    string s;
    cin >> s;

    k--;
    string t = s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            t[i] = '0';
        }
        else if (i > 0 && s[i - 1] == '1')
        {
            t[i] = '1';
        }
        else if (i < n - 1 && s[i + 1] == '1')
        {
            t[i] = '1';
        }
        else
        {
            t[i] = '0';
        }
    }
    swap(s, t);
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            st.emplace(i);
        }
    }
    if (k == 0)
    {
        cout << s << '\n';
        return;
    }

    string ans;
    for (int i = 0; i < n; i++)
    {
        auto it = st.lower_bound(i);
        int d = k + 1;
        if (it != st.end())
        {
            d = min(d, *it - i);
        }

        if (it != st.begin())
        {
            it--;
            d = min(d, i - *it);
        }

        if (d <= k and d % 2 == k % 2)
        {
            ans += "1";
        }
        else
        {
            ans += "0";
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