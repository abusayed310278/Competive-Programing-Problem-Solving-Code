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

/*
consider the one-pile game with the rule that you may remove c chips from a pile of n chips iff c is a divisor
of n, including 1 and n.for example,from a pile a pile of 12 chips,you may remove 1,2,3,4,6 or 12 chips.the
only terminal position is 0. find the sprague-grundy function.1

*/

map<int, int> mp;
int grundy(int n)
{

    if (n == 0)
        return 0;
    if (mp.count(n))
        return mp[n];

    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {

            st.insert(grundy(n - i));
        }
    }

    int mex = 0;
    while (1)
    {
        if (st.find(mex) != st.end())
            mex++;
        else
            return mp[n]  = mex;
    }
}

void solve()
{
    for (int i = 0; i <= 10; i++)
    {
        cout << i << "->" << grundy(i) << endl;
    }
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