#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long int
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
    int n, x, y;
    cin >> n >> x >> y;
    multiset<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }

    while (y > 0)
    {

        int u = *st.begin();
        int v = u ^ x;
        if (v < u)
            break;
        y--;
        st.erase(st.begin());
        st.insert(v);
    }

    if (y % 2 == 1)
    {
        int u = *st.begin();
        st.erase(st.begin());
        int v = u ^ x;
        st.insert(v);

    }

    for (auto x : st)
        cout << x << " ";

    cout << endl;
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