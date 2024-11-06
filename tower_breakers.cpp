#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
#define ll long long
#define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

void print(int x)
{

    if (x == 1)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
}

void solve()
{

    int n, nimsum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        nimsum = nimsum ^ a[i];
    }

    sort(a, a + n);
    if (a[0] == a[n - 1])
    {
        if (n % 2 == 0)
            print(1);
        else
            print(2);
    }
    else
    {
        if (nimsum)
            print(1);
        else
            print(2);
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