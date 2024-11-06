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

//grundy function for simple take away game

int grundy(int n)
{

    if (n == 0)
        return 0;
    set<int> st;
    for (int i = n - 1; i >= n - 3 and i >= 0; i--)
    {
        st.insert(grundy(i));
    }

    int mex = 0;
    while (1)
    {
        if (st.find(mex) != st.end())
            mex++;
        else
            return mex;
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