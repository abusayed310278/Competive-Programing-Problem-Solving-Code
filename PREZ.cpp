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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int low = 0, hi = n+1;
    while (hi - low > 1)
    {
        int mid = (hi + low) / 2;
        int ops = 0;
        for (int i = mid - 1; i >= 0; i--)
        {
            int req = (ops + s[i] - '0')%10;
            if (req != 0)
                ops += 10 - req;
        }

        if (ops <= k)
            low = mid;
        else
            hi = mid;
    }

    cout << low << endl;
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