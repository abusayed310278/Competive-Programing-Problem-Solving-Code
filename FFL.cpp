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
    int n, s;
    cin >> n >> s;

    vector<int> p(n);
    for (auto &x : p)
        cin >> x;

    set<int> st0, st1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
            st1.insert(p[i]);
        else
            st0.insert(p[i]);
    }

    int rem = 100 - s;

    if (*st0.begin() + *st1.begin() <= rem and (st0.size() > 0 and st1.size() > 0))
    {
        cout << "yes\n";
    }
    else
    {

        cout << "no\n";
    }
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