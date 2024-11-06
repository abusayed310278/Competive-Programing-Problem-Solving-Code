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
    int N;
    cin >> N;

    string s;
    cin >> s;

    vector<int> a(2 * N + 1);
    for (int i = 0; i < 2 * N; i++)
    {
        a[i + 1] = s[i] - '0';
    }

    int scA = 0, scB = 0;
    int leftA = N, leftB = N;

    int i;
    for (i = 1; i <= 2 * N; i++)
    {
        if (i % 2 == 1)
        {
            scA += a[i];
            leftA--;
        }
        else
        {
            scB += a[i];
            leftB--;
        }

        if ((scA > scB + leftB) || (scB > scA + leftA) || (scA == scB && i == 2 * N))
        {
            break;
        }
    }

    cout << i << "\n";
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