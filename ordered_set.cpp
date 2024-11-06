#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define ordered_set  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{

    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][1];
    }

    sort(begin(a), end(a));
    ordered_set<int> os;
    int max_score = -1;
    map<int, int> mp;

    for (int i = n - 1; i >= 0; i--)
    {
        int cur_score = i + os.order_of_key(a[i][1]);
        mp[cur_score]++;
        max_score = max(max_score, cur_score);

        os.insert(a[i][1]);
    }

    cout << mp[max_score] << endl;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}