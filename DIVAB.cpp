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
    int a, b, n;
    cin >> a >> b >> n;
    if (a % b == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        int num = (n / a + 1) * a;

        if (num % a == 0)
            num -= a;
        if (num % b == 0)
            num += a;

        cout << num << endl;
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