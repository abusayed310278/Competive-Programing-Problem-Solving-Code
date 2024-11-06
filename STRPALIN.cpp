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
    string s, t;
    cin >> s >> t;
    vector<int> v1(26, 0), v2(26, 0);
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        v1[s[i] - 'a']++;
    }

    // for (int i = 0; i < 26; i++)
    // {
    //     cout << i << " "<<a[i]<<endl;
    // }

    int m = t.size();
    for (int i = 0; i < m; i++)
    {
        v2[t[i] - 'a']++;
    }

    bool flag = false;
    for (int i = 0; i < 26; i++)
    {
        if (v1[i] and v2[i])
        {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << "Yes\n";
    else
        cout << "No\n";
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