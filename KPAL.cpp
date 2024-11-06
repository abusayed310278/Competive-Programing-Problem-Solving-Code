#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define int long long
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
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> b = a;
    reverse(begin(b), end(b));

    if (a == b)
    {
        cout << "yes\n";
    }
    else
    {
        if (k == n)
        {
            cout << "no\n";
        }
        else if (n % 2 == 1 or k % 2 == 1)
        {
            cout << "yes\n";
        }
        else
        {
            int sum = accumulate(begin(a), end(a), 0LL);
            if (sum % 2 == 0)
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
    }
}

int32_t main()
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