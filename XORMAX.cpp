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
    string a, b;
    cin >> a >> b;
    int n = a.size();

    int zeroa = count(begin(a), end(a), '0');
    int onea = n - zeroa;

    int zerob = count(begin(b), end(b), '0');
    int oneb = n - zerob;

    int one = 0, zero = 0;
    one += min(zeroa, oneb) + min(zerob, onea);

    zero = n - one;
    string s = "";
    for (int i = 0; i < one; i++)
    {
        s += '1';
    }
    for (int i = 0; i < zero; i++)
    {
        s += '0';
    }

    cout << s << endl;
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