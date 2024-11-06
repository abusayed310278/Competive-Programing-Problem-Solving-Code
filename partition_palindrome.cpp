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
int dp[101];

bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }

        i++;
        j--;
    }
    return true;
}

int f(int i, int n, string &s)
{

    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int ans = INT_MAX;
    for (int j = i; j < n; j++)
    {

        if (isPalindrome(i, j, s))
        {
            int cost = 1 + f(j + 1, n, s);
            ans = min(ans, cost);
        }
    }

    return dp[i] = ans;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    string s;
    cin >> s;

    cout << f(0, s.size(), s)-1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}