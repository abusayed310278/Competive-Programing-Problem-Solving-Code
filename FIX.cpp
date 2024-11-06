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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll maxi = *max_element(begin(a), end(a));
    set<ll> st;

    for (auto i : a)
    {
        if (st.find(i) == st.end())
        {
            cout << i << " ";
        }
        else
        {
            cout << maxi << " ";
        }

        st.insert(i);
    }

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