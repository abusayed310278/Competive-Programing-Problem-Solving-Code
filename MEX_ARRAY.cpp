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

int find_mex(unordered_set<int> &st)
{
    int mex = 0;
    while (1)
    {
        if (st.find(mex) != st.end())
        {
            mex++;
        }
        else
        {
            return mex;
        }
    }
}

void solve()
{
    // Write your solution code here

    vector<int> b;
    cout << b.size() << endl;
    for (auto x : b)
    {
        cout << x << " ";
    }
    cout << endl;
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