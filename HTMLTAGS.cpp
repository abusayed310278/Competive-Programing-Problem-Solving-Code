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

    string s;
    cin >> s;
    int n = s.length();

    if (n < 4 or s.substr(0, 2) != "</" or s[n - 1] != '>')
    {
        cout << "Error\n";
        return;
    }

    bool is_valid = true;
    for (int i = 2; i < n - 1; i++)
    {
        bool is_alpha = (s[i] >= 'a' and s[i] <= 'z');
        bool is_num = (s[i] >= '0' and s[i] <= '9');
        if (!is_alpha and !is_num)
        {
            is_valid = false;
            break;
        }
    }

    cout << (is_valid ? "Success" : "Error") << endl;
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