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
    int n, p;
    cin >> n >> p;
    int c = 0, h = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x >= (int)p / 2)
            c++;
        else if (x <= (int)p / 10)
            h++;
    }

    if (c == 1 and h == 2)
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