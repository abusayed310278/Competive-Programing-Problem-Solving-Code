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
    string s, t;
    int n;
    cin >> n >> s >> t;

    string one_zero = "", zero_one = "";
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            one_zero += '1', zero_one += '0';
        }
        else
        {
            one_zero += '0', zero_one += '1';
        }
    }
    int one = count(begin(s), end(s), '1');

    if (one)
    {
        if (t == one_zero or t == zero_one)
        {
            if (s == t)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            cout << "YES\n";
        }
    }
    else
    {
        if (s == t)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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