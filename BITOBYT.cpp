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
    int n;
    cin >> n;
    int bit = 0, nibble = 0, byte = 0;
    if (n <= 2)
    {
        bit++;
    }
    else if (n >= 3 and n <= 8)
    {
        nibble++;
    }
    else if (n >= 9 and n <= 16)
    {
        byte++;
    }
    else
    {
        bit += 2;
    }

    cout << bit << " " << nibble << " " << byte << endl;
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