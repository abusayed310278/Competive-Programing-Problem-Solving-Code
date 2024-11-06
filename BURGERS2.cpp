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
    int x, y, n, r;
    cin >> x >> y >> n >> r;
    if (x > r or y > r)
    {
        cout << -1 << endl;
        return;
    }

    int rem = 0;
    rem += r % y;
    int time = r / y;

    int c = 0;
    while (time)
    {
        c = rem / x;
        if (n == time + c)
            break;

        rem += y;
        time--;
    }

    cout << c << " " << time << endl;
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