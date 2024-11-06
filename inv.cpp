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
vector<int> fn;

// build and update
void update(int i, int x)
{

    while (i <= fn.size())
    {
        fn[i] += x;
        i += i & (-i);
    }
}

/*void add(int i)
{

    while (i<=fn.size())
    {
        fn[i]++;
        i += i & (-i);
    }
}*/

int getsum(int i)
{

    int sum = 0;
    while (i > 0)
    {
        sum += fn[i];
        i -= i & (-i);
    }

    return sum;
}

void solve()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    vector<int> temp = a;
    sort(begin(temp), end(temp));
    fn.resize(n + 1);

    // for(auto x:temp)cout<<x<<" ";

    for (int i = 0; i < n; i++)
    {
        a[i] = lower_bound(begin(temp), end(temp), a[i]) - begin(temp) + 1;
    }

    int inv = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        inv += getsum(a[i] - 1);
        update(a[i], 1);
    }

    // for(auto x:fn)cout<<x<<" ";

    cout << inv << endl;
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

/*
8
3 5 6 9 1 2 6 7

*/