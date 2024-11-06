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

bool check(int a, int b, int c)
{

    if (a == b or b == c or c == a)
        return true;

    return false;
}

void solve()
{
    // Write your solution code here
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    if (check(a + m, b, c))
        cout << "YES\n";
    else if (check(a, b + m, c))
        cout << "YES\n";
    else if (check(a, b, c + m))
        cout << "YES\n";
    else
    {
        cout << "NO\n";
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