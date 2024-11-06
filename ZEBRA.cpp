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

    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        cnt += (s[i - 1] != s[i]) ? 1 : 0;
    }

    if (cnt >= k)
    {

        for (int i = n - 1; i >= 0; i--)
        {

            if ((k & 1) and s[i] != s[0])
            {
                cout << i + 1 << endl;
                break;
            }
            else if (!(k & 1) and s[i] == s[0])
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    else
    {
        cout << -1 << endl;
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