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
    string s;
    cin >> s;

    int one = count(begin(s), end(s), '1');
    int zero = count(begin(s), end(s), '0');

    int cnt = min(one, zero);

    if (cnt % 2 == 0)
    {
        cout << "Ramos\n";
    }
    else
    {
        cout << "Zlatan\n";
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