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
const int N = 1e5 + 1;

bool check(string s)
{
    string t = s;
    reverse(begin(t), end(t));
    if (s == t)
        return true;

    return false;
}

vector<int> p;

void pre()
{

    for (int i = 1; i <= N; i++)
    {
        if (check(to_string(i)))
        {

            p.push_back(i);
        }
    }
}

void solve()
{
    // Write your solution code here
    int L, R;
    cin >> L >> R;
    int sum = 0;
    for (auto x : p)
    {
        if (x >= L and x <= R)
            sum += x;
    }

    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    pre();
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}