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

    int a, b, a1, b1, a2, b2;
    cin >> a >> b >> a1 >> b1 >> a2 >> b2;

    set<pair<int, int>> st;

    if (a > b)
    {
        swap(a, b);
    }
    st.insert({a, b});
    // cout << a << " " << b << endl;

    if (a1 > b1)
    {
        swap(a1, b1);
    }

    if (a2 > b2)
    {
        swap(a2, b2);
    }

    if (st.find({a1, b1}) != st.end())
    {
        cout << 1 << endl;
        return;
    }

    if (st.find({a2, b2}) != st.end())
    {
        cout << 2 << endl;
        return;
    }

    cout << 0 << endl;
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