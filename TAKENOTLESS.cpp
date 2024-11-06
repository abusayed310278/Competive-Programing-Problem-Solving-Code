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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    if (n == 1)
    {
        cout << "Marichka" << endl;
        return;
    }

    sort(begin(v), end(v), greater<int>());

    if (v[0] > v[1])
    {
        cout << "Marichka" << endl;
    }
    else if (v[0] == v[1])
    {
        if (n & 1)
            cout << "Marichka" << endl;
        else
            cout << "Zenyk" << endl;
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