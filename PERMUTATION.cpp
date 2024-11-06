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
    vector<int> a(n);

    int flag = 0;
    for (auto &x : a)
    {
        cin >> x;
    }

    sort(begin(a), end(a));

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > i + 1)
        {
            flag = -1;
        }
        else
        {
            sum += i + 1 - a[i];
        }
    }

    if (flag == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << sum << endl;
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